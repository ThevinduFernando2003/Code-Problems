"""Rock Paper Scissors. Press 1 rock, 2 paper, 3 scissors."""

import random
import pygame

CHOICES = ["rock", "paper", "scissors"]
BEATS = {"rock": "scissors", "paper": "rock", "scissors": "paper"}


def main():
    pygame.init()
    screen = pygame.display.set_mode((720, 420))
    pygame.display.set_caption("Rock Paper Scissors")
    font = pygame.font.SysFont("consolas", 32)
    small = pygame.font.SysFont("consolas", 22)

    message = "Press 1 rock  2 paper  3 scissors"
    score = [0, 0]
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                pick = None
                if event.key in (pygame.K_1, pygame.K_KP1):
                    pick = "rock"
                if event.key in (pygame.K_2, pygame.K_KP2):
                    pick = "paper"
                if event.key in (pygame.K_3, pygame.K_KP3):
                    pick = "scissors"
                if pick:
                    cpu = random.choice(CHOICES)
                    if pick == cpu:
                        result = "Draw"
                    elif BEATS[pick] == cpu:
                        result = "You win"
                        score[0] += 1
                    else:
                        result = "CPU wins"
                        score[1] += 1
                    message = f"You: {pick}   CPU: {cpu}   {result}"

        screen.fill((18, 24, 36))
        screen.blit(font.render("Rock Paper Scissors", True, (240, 240, 250)), (40, 40))
        screen.blit(small.render(message, True, (220, 220, 230)), (40, 180))
        screen.blit(small.render(f"Score  You {score[0]}  CPU {score[1]}", True, (160, 220, 160)), (40, 240))
        screen.blit(small.render("Keys: 1 rock  2 paper  3 scissors", True, (160, 170, 190)), (40, 340))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
