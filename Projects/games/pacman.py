"""Simple Pac-Man maze. Arrow keys. Eat dots, avoid the ghost."""

import pygame

CELL = 32
MAZE = [
    "#####################",
    "#.........#.........#",
    "#.###.###.#.###.###.#",
    "#...................#",
    "#.###.#.#####.#.###.#",
    "#.....#...#...#.....#",
    "#####.###.#.###.#####",
    "#.........#.........#",
    "#####.###.#.###.#####",
    "#.....#.......#.....#",
    "#.###.#########.###.#",
    "#...................#",
    "#####################",
]
ROWS, COLS = len(MAZE), len(MAZE[0])
WIDTH, HEIGHT = COLS * CELL, ROWS * CELL + 40


def cells(ch):
    return [(c, r) for r, row in enumerate(MAZE) for c, tile in enumerate(row) if tile == ch]


def open_neighbors(x, y):
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = x + dx, y + dy
        if 0 <= ny < ROWS and 0 <= nx < COLS and MAZE[ny][nx] != "#":
            yield nx, ny


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Pac-Man")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        dots = set(cells("."))
        player = (1, 1)
        ghost = (COLS - 2, ROWS - 2)
        return dots, player, ghost, 0, False

    dots, player, ghost, score, dead = reset()
    tick = 0
    running = True

    while running:
        move = (0, 0)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    dots, player, ghost, score, dead = reset()
                if event.key == pygame.K_LEFT:
                    move = (-1, 0)
                if event.key == pygame.K_RIGHT:
                    move = (1, 0)
                if event.key == pygame.K_UP:
                    move = (0, -1)
                if event.key == pygame.K_DOWN:
                    move = (0, 1)

        if not dead and move != (0, 0):
            nx, ny = player[0] + move[0], player[1] + move[1]
            if MAZE[ny][nx] != "#":
                player = (nx, ny)
                if player in dots:
                    dots.remove(player)
                    score += 10

        tick += 1
        if not dead and tick % 12 == 0:
            options = list(open_neighbors(*ghost))
            if options:
                options.sort(key=lambda p: abs(p[0] - player[0]) + abs(p[1] - player[1]))
                ghost = options[0]
        if player == ghost:
            dead = True

        screen.fill((10, 10, 20))
        pygame.draw.rect(screen, (20, 20, 35), (0, 0, WIDTH, 40))
        status = "You win!" if not dots else ("Caught! R restart" if dead else f"Score {score}")
        screen.blit(font.render(status, True, (240, 240, 240)), (10, 8))
        for y, row in enumerate(MAZE):
            for x, tile in enumerate(row):
                px, py = x * CELL, 40 + y * CELL
                if tile == "#":
                    pygame.draw.rect(screen, (30, 60, 160), (px, py, CELL - 1, CELL - 1))
        for x, y in dots:
            pygame.draw.circle(screen, (250, 230, 140), (x * CELL + CELL // 2, 40 + y * CELL + CELL // 2), 4)
        pygame.draw.circle(screen, (255, 220, 40), (player[0] * CELL + CELL // 2, 40 + player[1] * CELL + CELL // 2), 12)
        pygame.draw.circle(screen, (240, 80, 80), (ghost[0] * CELL + CELL // 2, 40 + ghost[1] * CELL + CELL // 2), 12)
        pygame.display.flip()
        clock.tick(30)

    pygame.quit()


if __name__ == "__main__":
    main()
