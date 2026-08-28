"""Dice roller. Space to roll 1-6."""

import random
import pygame


def pip_positions(value):
    spots = {
        1: [(0.5, 0.5)],
        2: [(0.25, 0.25), (0.75, 0.75)],
        3: [(0.25, 0.25), (0.5, 0.5), (0.75, 0.75)],
        4: [(0.25, 0.25), (0.75, 0.25), (0.25, 0.75), (0.75, 0.75)],
        5: [(0.25, 0.25), (0.75, 0.25), (0.5, 0.5), (0.25, 0.75), (0.75, 0.75)],
        6: [(0.25, 0.25), (0.75, 0.25), (0.25, 0.5), (0.75, 0.5), (0.25, 0.75), (0.75, 0.75)],
    }
    return spots[value]


def main():
    pygame.init()
    screen = pygame.display.set_mode((480, 420))
    pygame.display.set_caption("Dice")
    font = pygame.font.SysFont("consolas", 24)
    value = 1
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_SPACE:
                    value = random.randint(1, 6)

        screen.fill((30, 50, 40))
        screen.blit(font.render("Space to roll", True, (230, 230, 230)), (20, 20))
        die = pygame.Rect(140, 100, 200, 200)
        pygame.draw.rect(screen, (245, 245, 245), die, border_radius=24)
        for px, py in pip_positions(value):
            pygame.draw.circle(screen, (30, 30, 30), (int(die.x + px * die.w), int(die.y + py * die.h)), 16)
        screen.blit(font.render(f"Rolled {value}", True, (240, 240, 240)), (180, 340))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
