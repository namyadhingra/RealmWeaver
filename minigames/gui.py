import tkinter as tk
from tkinter import messagebox
import g1_memoryCardMatching
import g2_treasureHuntMaze
import g3_wordScramble
import threading

# Function to start memory game
def start_memory_game():
    num_pairs = int(entry_memory_pairs.get())
    
    def run_game():
        result = g1_memoryCardMatching.memoryGame(num_pairs)
        messagebox.showinfo("Memory Game Result", result)
    
    game_thread = threading.Thread(target=run_game)
    game_thread.start()

# Function to start treasure hunt game
def start_treasure_hunt():
    level = int(entry_treasure_level.get())
    
    def run_game():
        result = g2_treasureHuntMaze.treasureHunt(level)
        messagebox.showinfo("Treasure Hunt Result", result)
    
    game_thread = threading.Thread(target=run_game)
    game_thread.start()

# Function to start word scramble game
def start_word_scramble():
    difficulty = entry_word_difficulty.get()
    
    def run_game():
        result = g3_wordScramble.wordScramble(difficulty)
        messagebox.showinfo("Word Scramble Result", result)
    
    game_thread = threading.Thread(target=run_game)
    game_thread.start()

# Set up GUI
root = tk.Tk()
root.title("Minigames Interface")

# Memory Game Section
tk.Label(root, text="Memory Game: Enter Number of Pairs").pack()
entry_memory_pairs = tk.Entry(root)
entry_memory_pairs.pack()
tk.Button(root, text="Start Memory Game", command=start_memory_game).pack()

# Treasure Hunt Game Section
tk.Label(root, text="Treasure Hunt Game: Enter Difficulty Level").pack()
entry_treasure_level = tk.Entry(root)
entry_treasure_level.pack()
tk.Button(root, text="Start Treasure Hunt Game", command=start_treasure_hunt).pack()

# Word Scramble Game Section
tk.Label(root, text="Word Scramble Game: Enter Difficulty Level").pack()
entry_word_difficulty = tk.Entry(root)
entry_word_difficulty.pack()
tk.Button(root, text="Start Word Scramble Game", command=start_word_scramble).pack()

# Run the main loop
root.mainloop()