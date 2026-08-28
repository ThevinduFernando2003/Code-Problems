"""Sudoku. Click a cell, type 1-9, Backspace clears, R new puzzle."""

import copy
import random
import pygame

CELL = 54
SIZE = CELL * 9
PUZZLE = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9],
]


def valid(board, r, c, n):
    if n in board[r]:
        return False
    if n in [board[i][c] for i in range(9)]:
        return False
    br, bc = 3 * (r // 3), 3 * (c // 3)
    for i in range(br, br + 3):
        for j in range(bc, bc + 3):
            if board[i][j] == n:
                return False
    return True


def main():
    pygame.init()
    screen = pygame.display.set_mode((SIZE, SIZE + 50))
    pygame.display.set_caption("Sudoku")
    font = pygame.font.SysFont("consolas", 32)
    small = pygame.font.SysFont("consolas", 18)

    given = copy.deepcopy(PUZZLE)
    board = copy.deepcopy(PUZZLE)
    selected = (0, 0)
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r:
                board = copy.deepcopy(given)
            if event.type == pygame.MOUSEBUTTONDOWN:
                mx, my = event.pos
                if my < SIZE:
                    selected = (my // CELL, mx // CELL)
            if event.type == pygame.KEYDOWN:
                r, c = selected
                if given[r][c] != 0:
                    continue
                if event.key == pygame.K_BACKSPACE:
                    board[r][c] = 0
                if event.unicode.isdigit() and event.unicode != "0":
                    n = int(event.unicode)
                    if valid(board, r, c, n) or board[r][c] == n:
                        board[r][c] = n

        screen.fill((245, 245, 240))
        pygame.draw.rect(screen, (40, 40, 50), (0, SIZE, SIZE, 50))
        screen.blit(small.render("Click cell, 1-9 to fill, Backspace clear, R reset", True, (230, 230, 230)), (10, SIZE + 14))
        sr, sc = selected
        pygame.draw.rect(screen, (210, 230, 255), (sc * CELL, sr * CELL, CELL, CELL))
        for r in range(9):
            for c in range(9):
                if given[r][c]:
                    pygame.draw.rect(screen, (230, 230, 225), (c * CELL, r * CELL, CELL, CELL))
                if board[r][c]:
                    color = (20, 20, 20) if given[r][c] else (30, 90, 180)
                    glyph = font.render(str(board[r][c]), True, color)
                    screen.blit(glyph, glyph.get_rect(center=(c * CELL + CELL // 2, r * CELL + CELL // 2)))
        for i in range(10):
            w = 4 if i % 3 == 0 else 1
            pygame.draw.line(screen, (20, 20, 20), (i * CELL, 0), (i * CELL, SIZE), w)
            pygame.draw.line(screen, (20, 20, 20), (0, i * CELL), (SIZE, i * CELL), w)
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
