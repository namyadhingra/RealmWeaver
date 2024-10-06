-- need to implement indexing to make it more efficient

-- Create database for the game
CREATE DATABASE GameDB;

-- Switch to the GameDB database
USE GameDB;


-- Create table for storing locations
CREATE TABLE Locations (
    location_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL UNIQUE,           -- Location name (unique)
    description TEXT,                            -- Description of the location
    `rank` INT NOT NULL,                           -- Rank of the location, used for game mechanics
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  -- Timestamp of when the location was created
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP  -- Updated timestamp
);

-- Create table for storing NPCs
CREATE TABLE NPCs (
    npc_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,                  -- NPC name
    description TEXT,                            -- Description of the NPC
    `rank` INT NOT NULL,                           -- NPC's rank, used to generate stats
    location_id INT,                             -- Location where the NPC is located (reference to Locations)
    FOREIGN KEY (location_id) REFERENCES Locations(location_id)
);

-- Create table for storing items
CREATE TABLE Items (
    item_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL UNIQUE,          -- Unique item name
    description TEXT,                           -- Description of the item
    `rank` INT NOT NULL,                          -- Rank of the item
    effect TEXT,                                -- Effects or properties of the item
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP  -- Timestamp of when the item was created
);

-- Create table for storing quests
CREATE TABLE Quests (
    quest_id INT AUTO_INCREMENT PRIMARY KEY,
    description TEXT,                           -- Description of the quest
    status ENUM('ongoing', 'completed', 'failed') DEFAULT 'ongoing',  -- Quest status
    npc_id INT,
    `rank` INT NOT NULL,                               -- NPC who gives the quest (reference to NPCs)
    FOREIGN KEY (npc_id) REFERENCES NPCs(npc_id),
    next_quest_id INT DEFAULT NULL,            -- Reference to the next quest in the chain (self-referencing)
    FOREIGN KEY (next_quest_id) REFERENCES Quests(quest_id)
);

-- Create table for storing quest stages
CREATE TABLE QuestStages (
    stage_id INT AUTO_INCREMENT PRIMARY KEY,
    quest_id INT,                              -- Reference to the Quests table
    description TEXT,                          -- Description of the quest stage
    is_completed BOOLEAN DEFAULT FALSE,        -- Stage completion status
    FOREIGN KEY (quest_id) REFERENCES Quests(quest_id)
);

-- Create table for storing games
CREATE TABLE Games (
    game_id INT AUTO_INCREMENT PRIMARY KEY,
    theme VARCHAR(255) NOT NULL,                  -- Theme of the game
    player_info TEXT,                             -- JSON containing player information
    current_location_id INT,                      -- Current location of the player (reference to Locations)
    level INT DEFAULT 1,                          -- Player's current level
    `rank` INT NOT NULL,
    FOREIGN KEY (current_location_id) REFERENCES Locations(location_id)
);

-- Create table for storing player inventories
CREATE TABLE PlayerInventories (
    inventory_id INT AUTO_INCREMENT PRIMARY KEY,
    game_id INT,                                -- Reference to the Games table
    item_id INT,                                -- Reference to the Items table
    quantity INT DEFAULT 1,                     -- Quantity of the item
    FOREIGN KEY (game_id) REFERENCES Games(game_id),
    FOREIGN KEY (item_id) REFERENCES Items(item_id)
);
