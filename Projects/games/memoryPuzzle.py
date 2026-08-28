"""Memory match puzzle. Click two cards to find pairs."""

import random
import pygame

COLS, ROWS = 4, 4
CELL = 90
GAP = 10
MARGIN = 20
WIDTH = MARGIN * 2 + COLS * (CELL + GAP)
HEIGHT = MARGIN * 2 + ROWS * (CELL + GAP) + 40


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Memory Puzzle")
    font = pygame.font.SysFont("consolas", 36)
    small = pygame.font.SysFont("consolas", 20)

    symbols = list("ABCDEFGH") * 2
    random.shuffle(symbols)
    board = [symbols[i * COLS : (i + 1) * COLS] for i in range(ROWS)]
    revealed = [[False] * COLS for _ in range(ROWS)]
    matched = [[False] * COLS for _ in range(ROWS)]
    first = None
    hide_at = 0
    pending = None
    moves = 0
    running = True

    while running:
        now = pygame.time.get_ticks()
        if pending and now >= hide_at:
            r, c, r1, c1 = pending
            if not matched[r][c]:
                revealed[r][c] = False
            if not matched[r1][c1]:
                revealed[r1][c1] = False
            pending = None

        locked = pending is not None
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN and not locked:
                mx, my = event.pos
                c = (mx - MARGIN) // (CELL + GAP)
                r = (my - MARGIN) // (CELL + GAP)
                if 0 <= r < ROWS and 0 <= c < COLS and not matched[r][c] and not revealed[r][c]:
                    revealed[r][c] = True
                    if first is None:
                        first = (r, c)
                    else:
                        r1, c1 = first
                        moves += 1
                        if board[r][c] == board[r1][c1]:
                            matched[r][c] = matched[r1][c1] = True
                        else:
                            pending = (r, c, r1, c1)
                            hide_at = now + 700
                        first = None

        screen.fill((24, 28, 40))
        won = all(all(row) for row in matched)
        screen.blit(
            small.render(f"Moves {moves}" + ("  You win!" if won else ""), True, (230, 230, 240)),
            (MARGIN, HEIGHT - 36),
        )
        for r in range(ROWS):
            for c in range(COLS):
                x = MARGIN + c * (CELL + GAP)
                y = MARGIN + r * (CELL + GAP)
                rect = pygame.Rect(x, y, CELL, CELL)
                show = matched[r][c] or revealed[r][c]
                pygame.draw.rect(screen, (80, 140, 220) if not show else (230, 230, 220), rect, border_radius=8)
                if show:
                    glyph = font.render(board[r][c], True, (30, 30, 40))
                    screen.blit(glyph, glyph.get_rect(center=rect.center))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
