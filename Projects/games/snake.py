"""Classic Snake. Arrow keys to move, R to restart, Esc to quit."""

import random
import pygame

CELL = 24
COLS, ROWS = 28, 20
WIDTH, HEIGHT = COLS * CELL, ROWS * CELL + 40


def spawn_food(snake):
    while True:
        pos = (random.randrange(COLS), random.randrange(ROWS))
        if pos not in snake:
            return pos


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Snake")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        snake = [(8, 10), (7, 10), (6, 10)]
        return snake, (1, 0), spawn_food(snake), 0, False

    snake, direction, food, score, dead = reset()
    pending = direction
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    snake, direction, food, score, dead = reset()
                    pending = direction
                if event.key == pygame.K_UP and direction != (0, 1):
                    pending = (0, -1)
                if event.key == pygame.K_DOWN and direction != (0, -1):
                    pending = (0, 1)
                if event.key == pygame.K_LEFT and direction != (1, 0):
                    pending = (-1, 0)
                if event.key == pygame.K_RIGHT and direction != (-1, 0):
                    pending = (1, 0)

        if not dead:
            direction = pending
            head = (snake[0][0] + direction[0], snake[0][1] + direction[1])
            if head[0] < 0 or head[0] >= COLS or head[1] < 0 or head[1] >= ROWS or head in snake:
                dead = True
            else:
                snake.insert(0, head)
                if head == food:
                    score += 10
                    food = spawn_food(snake)
                else:
                    snake.pop()

        screen.fill((16, 20, 16))
        pygame.draw.rect(screen, (30, 40, 30), (0, 0, WIDTH, 40))
        screen.blit(font.render(f"Score: {score}   R restart", True, (230, 230, 230)), (10, 8))
        for x, y in snake:
            pygame.draw.rect(screen, (80, 200, 90), (x * CELL, 40 + y * CELL, CELL - 1, CELL - 1))
        pygame.draw.rect(screen, (220, 70, 70), (food[0] * CELL, 40 + food[1] * CELL, CELL - 1, CELL - 1))
        if dead:
            overlay = font.render("Game over  R to restart", True, (255, 220, 120))
            screen.blit(overlay, overlay.get_rect(center=(WIDTH // 2, HEIGHT // 2)))
        pygame.display.flip()
        clock.tick(10)

    pygame.quit()


if __name__ == "__main__":
    main()
