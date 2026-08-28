"""Tic Tac Toe. Click a cell to place X or O."""

import pygame

SIZE = 540
CELL = SIZE // 3


def winner(board):
    lines = board + [list(col) for col in zip(*board)]
    lines.append([board[i][i] for i in range(3)])
    lines.append([board[i][2 - i] for i in range(3)])
    for line in lines:
        if line[0] and line.count(line[0]) == 3:
            return line[0]
    if all(cell for row in board for cell in row):
        return "Draw"
    return None


def main():
    pygame.init()
    screen = pygame.display.set_mode((SIZE, SIZE + 60))
    pygame.display.set_caption("Tic Tac Toe")
    font = pygame.font.SysFont("consolas", 72)
    small = pygame.font.SysFont("consolas", 24)

    board = [[""] * 3 for _ in range(3)]
    turn = "X"
    result = None
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key in (pygame.K_ESCAPE,):
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r:
                board = [[""] * 3 for _ in range(3)]
                turn = "X"
                result = None
            if event.type == pygame.MOUSEBUTTONDOWN and not result:
                mx, my = event.pos
                if my < SIZE:
                    col, row = mx // CELL, my // CELL
                    if not board[row][col]:
                        board[row][col] = turn
                        result = winner(board)
                        turn = "O" if turn == "X" else "X"

        screen.fill((24, 24, 32))
        pygame.draw.rect(screen, (40, 40, 55), (0, SIZE, SIZE, 60))
        status = result if result else f"{turn} to move   R restart"
        screen.blit(small.render(status, True, (240, 240, 240)), (16, SIZE + 18))
        for i in range(1, 3):
            pygame.draw.line(screen, (200, 200, 210), (i * CELL, 0), (i * CELL, SIZE), 4)
            pygame.draw.line(screen, (200, 200, 210), (0, i * CELL), (SIZE, i * CELL), 4)
        for r in range(3):
            for c in range(3):
                if board[r][c]:
                    color = (90, 190, 255) if board[r][c] == "X" else (255, 140, 90)
                    glyph = font.render(board[r][c], True, color)
                    screen.blit(glyph, glyph.get_rect(center=(c * CELL + CELL // 2, r * CELL + CELL // 2)))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
