"""Speed typing test. Type the prompt as fast as you can."""

import time
import pygame

PROMPT = "the quick brown fox jumps over the lazy python pygame practice game"


def main():
    pygame.init()
    screen = pygame.display.set_mode((900, 320))
    pygame.display.set_caption("Speed Typing Test")
    font = pygame.font.SysFont("consolas", 28)
    small = pygame.font.SysFont("consolas", 20)

    typed = ""
    started = None
    finished = False
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    typed, started, finished = "", None, False
                if finished:
                    continue
                if event.key == pygame.K_BACKSPACE:
                    typed = typed[:-1]
                elif event.unicode and event.unicode.isprintable():
                    if started is None:
                        started = time.time()
                    typed += event.unicode
                    if typed == PROMPT:
                        finished = True

        elapsed = (time.time() - started) if started else 0
        wpm = 0
        if elapsed > 0:
            wpm = (len(typed) / 5) / (elapsed / 60)

        screen.fill((22, 24, 32))
        screen.blit(small.render("Type the line. Backspace fixes. R restart.", True, (180, 180, 190)), (20, 20))
        screen.blit(font.render(PROMPT, True, (120, 140, 160)), (20, 90))
        color = (120, 220, 140) if typed == PROMPT[: len(typed)] else (240, 120, 120)
        screen.blit(font.render(typed + ("|" if not finished else ""), True, color), (20, 140))
        stats = f"{elapsed:.1f}s   {wpm:.0f} WPM"
        if finished:
            stats += "   Done!"
        screen.blit(small.render(stats, True, (240, 240, 240)), (20, 240))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
