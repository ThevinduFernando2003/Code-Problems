"""Snake Water Gun. 1 snake, 2 water, 3 gun."""

import random
import pygame

CHOICES = ["snake", "water", "gun"]
WINS = {("snake", "water"), ("water", "gun"), ("gun", "snake")}


def main():
    pygame.init()
    screen = pygame.display.set_mode((720, 400))
    pygame.display.set_caption("Snake Water Gun")
    font = pygame.font.SysFont("consolas", 28)
    small = pygame.font.SysFont("consolas", 20)
    message = "1 snake  2 water  3 gun"
    score = [0, 0]
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                pick = {pygame.K_1: "snake", pygame.K_2: "water", pygame.K_3: "gun"}.get(event.key)
                if pick:
                    cpu = random.choice(CHOICES)
                    if pick == cpu:
                        result = "Draw"
                    elif (pick, cpu) in WINS:
                        result = "You win"
                        score[0] += 1
                    else:
                        result = "CPU wins"
                        score[1] += 1
                    message = f"You {pick}  CPU {cpu}  {result}"

        screen.fill((20, 28, 24))
        screen.blit(font.render("Snake Water Gun", True, (230, 240, 230)), (40, 40))
        screen.blit(small.render(message, True, (210, 220, 210)), (40, 160))
        screen.blit(small.render(f"You {score[0]}   CPU {score[1]}", True, (160, 220, 160)), (40, 220))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
