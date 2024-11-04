#1 am, 11 sep 2024
import pygame
import random

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
CASTLE_POS = (WIDTH - 100, HEIGHT // 2 - 100)
PLAYER_SIZE = 40
SOLDIER_SIZE = 30
PLAYER_SPEED = 5
SOLDIER_SPEED = 2

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)

# Set up the display
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Castle Siege")

# Player class
class Player:
    def __init__(self):
        self.rect = pygame.Rect(50, HEIGHT // 2, PLAYER_SIZE, PLAYER_SIZE)

    def move(self, dx, dy):
        self.rect.x += dx
        self.rect.y += dy
        # Boundaries
        self.rect.x = max(0, min(WIDTH - PLAYER_SIZE, self.rect.x))
        self.rect.y = max(0, min(HEIGHT - PLAYER_SIZE, self.rect.y))

    def draw(self):
        pygame.draw.rect(screen, BLUE, self.rect)

# Soldier class
class Soldier:
    def __init__(self):
        self.rect = pygame.Rect(random.randint(400, WIDTH - 100), random.randint(50, HEIGHT - 50), SOLDIER_SIZE, SOLDIER_SIZE)

    def move_toward_player(self, player):
        if self.rect.x > player.rect.x:
            self.rect.x -= SOLDIER_SPEED
        if self.rect.x < player.rect.x:
            self.rect.x += SOLDIER_SPEED
        if self.rect.y > player.rect.y:
            self.rect.y -= SOLDIER_SPEED
        if self.rect.y < player.rect.y:
            self.rect.y += SOLDIER_SPEED

    def draw(self):
        pygame.draw.rect(screen, RED, self.rect)

# Castle class
class Castle:
    def __init__(self):
        self.rect = pygame.Rect(CASTLE_POS[0], CASTLE_POS[1], 100, 100)
        self.hp = 100

    def take_damage(self):
        self.hp -= 1

    def draw(self):
        pygame.draw.rect(screen, BLACK, self.rect)
        # Health bar
        pygame.draw.rect(screen, RED, (self.rect.x, self.rect.y - 20, self.hp, 10))

# Game Loop
def game():
    player = Player()
    soldiers = [Soldier() for _ in range(5)]
    castle = Castle()
    
    clock = pygame.time.Clock()
    running = True

    while running:
        screen.fill(WHITE)
        
        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # Player movement
        keys = pygame.key.get_pressed()
        dx, dy = 0, 0
        if keys[pygame.K_LEFT]:
            dx = -PLAYER_SPEED
        if keys[pygame.K_RIGHT]:
            dx = PLAYER_SPEED
        if keys[pygame.K_UP]:
            dy = -PLAYER_SPEED
        if keys[pygame.K_DOWN]:
            dy = PLAYER_SPEED
        
        player.move(dx, dy)
        
        # Move soldiers toward the player
        for soldier in soldiers:
            soldier.move_toward_player(player)
        
        # Check if player collides with castle
        if player.rect.colliderect(castle.rect):
            castle.take_damage()

        # Draw elements
        player.draw()
        for soldier in soldiers:
            soldier.draw()
        castle.draw()

        # Check if castle is destroyed
        if castle.hp <= 0:
            font = pygame.font.SysFont(None, 55)
            text = font.render('Castle Destroyed!', True, RED)
            screen.blit(text, (WIDTH//2 - text.get_width()//2, HEIGHT//2 - text.get_height()//2))
            pygame.display.flip()
            pygame.time.wait(3000)
            running = False

        # Update display
        pygame.display.flip()
        clock.tick(60)

# Run the game
game()

# Quit Pygame
pygame.quit()