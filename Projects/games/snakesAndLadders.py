"""Snakes and Ladders. Space to roll. Two players take turns."""

import random
import pygame

CELL = 56
SNAKES = {16: 6, 47: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
LADDERS = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}


def square_pos(n):
    n -= 1
    row, col = divmod(n, 10)
    if row % 2:
        col = 9 - col
    x = col * CELL + CELL // 2
    y = (9 - row) * CELL + CELL // 2
    return x, y


def main():
    pygame.init()
    screen = pygame.display.set_mode((CELL * 10, CELL * 10 + 60))
    pygame.display.set_caption("Snakes and Ladders")
    font = pygame.font.SysFont("consolas", 16)
    big = pygame.font.SysFont("consolas", 22)

    positions = [1, 1]
    turn = 0
    last = 0
    winner = None
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    positions, turn, last, winner = [1, 1], 0, 0, None
                if event.key == pygame.K_SPACE and not winner:
                    last = random.randint(1, 6)
                    nxt = positions[turn] + last
                    if nxt <= 100:
                        positions[turn] = nxt
                        positions[turn] = SNAKES.get(positions[turn], positions[turn])
                        positions[turn] = LADDERS.get(positions[turn], positions[turn])
                    if positions[turn] == 100:
                        winner = turn
                    else:
                        turn = 1 - turn

        screen.fill((240, 236, 220))
        for n in range(1, 101):
            x, y = square_pos(n)
            color = (220, 230, 210) if ((n - 1) // 10 + (n - 1) % 10) % 2 == 0 else (200, 210, 190)
            pygame.draw.rect(screen, color, (x - CELL // 2, y - CELL // 2, CELL - 1, CELL - 1))
            screen.blit(font.render(str(n), True, (40, 40, 40)), (x - 18, y - 22))
        for start, end in LADDERS.items():
            pygame.draw.line(screen, (40, 140, 60), square_pos(start), square_pos(end), 4)
        for start, end in SNAKES.items():
            pygame.draw.line(screen, (180, 50, 50), square_pos(start), square_pos(end), 4)
        colors = ((40, 90, 200), (200, 90, 40))
        for i, pos in enumerate(positions):
            x, y = square_pos(pos)
            pygame.draw.circle(screen, colors[i], (x - 8 + i * 16, y + 8), 10)
        pygame.draw.rect(screen, (40, 40, 50), (0, CELL * 10, CELL * 10, 60))
        status = f"Player {winner + 1} wins! R restart" if winner is not None else f"Player {turn + 1}  last roll {last}  Space to roll"
        screen.blit(big.render(status, True, (240, 240, 240)), (12, CELL * 10 + 18))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
