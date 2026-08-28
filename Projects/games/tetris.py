"""Tetris. Left/Right move, Down drop, Up rotate, R restart."""

import random
import pygame

CELL = 28
COLS, ROWS = 10, 20
OX, OY = 40, 40
WIDTH, HEIGHT = OX * 2 + COLS * CELL + 180, OY * 2 + ROWS * CELL

SHAPES = {
    "I": [[(0, 1), (1, 1), (2, 1), (3, 1)]],
    "O": [[(1, 0), (2, 0), (1, 1), (2, 1)]],
    "T": [[(1, 0), (0, 1), (1, 1), (2, 1)]],
    "S": [[(1, 0), (2, 0), (0, 1), (1, 1)]],
    "Z": [[(0, 0), (1, 0), (1, 1), (2, 1)]],
    "J": [[(0, 0), (0, 1), (1, 1), (2, 1)]],
    "L": [[(2, 0), (0, 1), (1, 1), (2, 1)]],
}
COLORS = {
    "I": (80, 200, 220),
    "O": (240, 210, 70),
    "T": (170, 90, 200),
    "S": (90, 200, 110),
    "Z": (220, 80, 80),
    "J": (80, 110, 220),
    "L": (230, 150, 60),
}


def rotate(cells):
    return [(3 - y, x) for x, y in cells]


def collides(board, cells, px, py):
    for x, y in cells:
        nx, ny = px + x, py + y
        if nx < 0 or nx >= COLS or ny >= ROWS:
            return True
        if ny >= 0 and board[ny][nx]:
            return True
    return False


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Tetris")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def new_piece():
        name = random.choice(list(SHAPES))
        return name, list(SHAPES[name][0]), 3, 0

    def reset():
        board = [[None] * COLS for _ in range(ROWS)]
        return board, *new_piece(), 0, False, 0

    board, name, cells, px, py, score, dead, timer = reset()
    running = True

    while running:
        fall = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    board, name, cells, px, py, score, dead, timer = reset()
                if not dead:
                    if event.key == pygame.K_LEFT and not collides(board, cells, px - 1, py):
                        px -= 1
                    if event.key == pygame.K_RIGHT and not collides(board, cells, px + 1, py):
                        px += 1
                    if event.key == pygame.K_DOWN:
                        fall = True
                    if event.key == pygame.K_UP:
                        rotated = rotate(cells)
                        if not collides(board, rotated, px, py):
                            cells = rotated

        if not dead:
            timer += 1
            if timer > 30 or fall:
                timer = 0
                if not collides(board, cells, px, py + 1):
                    py += 1
                else:
                    for x, y in cells:
                        if py + y < 0:
                            dead = True
                            break
                        board[py + y][px + x] = name
                    cleared = 0
                    board[:] = [row for row in board if any(cell is None for cell in row)]
                    cleared = ROWS - len(board)
                    while len(board) < ROWS:
                        board.insert(0, [None] * COLS)
                    score += (0, 100, 300, 500, 800)[cleared]
                    name, cells, px, py = new_piece()
                    if collides(board, cells, px, py):
                        dead = True

        screen.fill((18, 18, 24))
        pygame.draw.rect(screen, (30, 30, 40), (OX - 2, OY - 2, COLS * CELL + 4, ROWS * CELL + 4), 2)
        for y, row in enumerate(board):
            for x, cell in enumerate(row):
                if cell:
                    pygame.draw.rect(screen, COLORS[cell], (OX + x * CELL, OY + y * CELL, CELL - 1, CELL - 1))
        for x, y in cells:
            pygame.draw.rect(
                screen, COLORS[name], (OX + (px + x) * CELL, OY + (py + y) * CELL, CELL - 1, CELL - 1)
            )
        screen.blit(font.render(f"Score {score}", True, (230, 230, 240)), (OX + COLS * CELL + 20, 50))
        screen.blit(font.render("Arrows move", True, (160, 160, 180)), (OX + COLS * CELL + 20, 90))
        screen.blit(font.render("Up rotate", True, (160, 160, 180)), (OX + COLS * CELL + 20, 120))
        if dead:
            screen.blit(font.render("Game over R", True, (255, 180, 120)), (OX + COLS * CELL + 20, 180))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
