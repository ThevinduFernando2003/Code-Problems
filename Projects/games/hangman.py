"""Hangman. Type letters to guess the word."""

import random
import pygame

WORDS = [
    "python", "pygame", "hangman", "keyboard", "function",
    "variable", "algorithm", "developer", "practice", "repository",
]


def main():
    pygame.init()
    screen = pygame.display.set_mode((720, 480))
    pygame.display.set_caption("Hangman")
    font = pygame.font.SysFont("consolas", 40)
    small = pygame.font.SysFont("consolas", 22)

    def reset():
        word = random.choice(WORDS)
        return word, set(), 0

    word, guessed, misses = reset()
    max_miss = 6
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                elif event.key == pygame.K_r:
                    word, guessed, misses = reset()
                elif event.unicode.isalpha() and misses < max_miss and set(word) - guessed:
                    letter = event.unicode.lower()
                    if letter not in guessed:
                        guessed.add(letter)
                        if letter not in word:
                            misses += 1

        hidden = " ".join(ch if ch in guessed else "_" for ch in word)
        won = set(word) <= guessed
        lost = misses >= max_miss

        screen.fill((20, 22, 30))
        screen.blit(small.render("Type letters   R restart", True, (200, 200, 210)), (20, 20))
        screen.blit(font.render(hidden, True, (250, 250, 250)), (40, 180))
        screen.blit(small.render(f"Misses: {misses}/{max_miss}", True, (255, 160, 160)), (40, 260))
        used = " ".join(sorted(guessed)) or "-"
        screen.blit(small.render(f"Guessed: {used}", True, (180, 200, 220)), (40, 300))

        gallows = [(120, 420), (120, 80), (280, 80), (280, 120)]
        pygame.draw.lines(screen, (180, 180, 190), False, [(80, 420), (160, 420), (120, 420), (120, 80), (280, 80), (280, 120)], 6)
        body = [
            ((280, 150), 28),
        ]
        if misses >= 1:
            pygame.draw.circle(screen, (240, 220, 180), (280, 150), 28, 3)
        if misses >= 2:
            pygame.draw.line(screen, (240, 220, 180), (280, 178), (280, 280), 3)
        if misses >= 3:
            pygame.draw.line(screen, (240, 220, 180), (280, 200), (240, 240), 3)
        if misses >= 4:
            pygame.draw.line(screen, (240, 220, 180), (280, 200), (320, 240), 3)
        if misses >= 5:
            pygame.draw.line(screen, (240, 220, 180), (280, 280), (250, 340), 3)
        if misses >= 6:
            pygame.draw.line(screen, (240, 220, 180), (280, 280), (310, 340), 3)

        if won:
            screen.blit(font.render("You won!", True, (120, 220, 140)), (400, 80))
        if lost:
            screen.blit(font.render(f"Word: {word}", True, (255, 140, 140)), (360, 80))

        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
