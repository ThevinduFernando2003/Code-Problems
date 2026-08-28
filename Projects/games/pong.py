"""Two-player Pong. W/S left paddle, Up/Down right paddle."""

import pygame

WIDTH, HEIGHT = 800, 500
PADDLE_W, PADDLE_H = 12, 90
BALL = 12
SPEED = 6


def clamp(value, low, high):
    return max(low, min(high, value))


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Pong")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 36)

    left = pygame.Rect(30, HEIGHT // 2 - PADDLE_H // 2, PADDLE_W, PADDLE_H)
    right = pygame.Rect(WIDTH - 42, HEIGHT // 2 - PADDLE_H // 2, PADDLE_W, PADDLE_H)
    ball = pygame.Rect(WIDTH // 2, HEIGHT // 2, BALL, BALL)
    vx, vy = 5, 4
    score = [0, 0]
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r:
                score = [0, 0]
                ball.center = (WIDTH // 2, HEIGHT // 2)
                vx, vy = 5, 4

        keys = pygame.key.get_pressed()
        if keys[pygame.K_w]:
            left.y -= SPEED
        if keys[pygame.K_s]:
            left.y += SPEED
        if keys[pygame.K_UP]:
            right.y -= SPEED
        if keys[pygame.K_DOWN]:
            right.y += SPEED
        left.y = clamp(left.y, 0, HEIGHT - PADDLE_H)
        right.y = clamp(right.y, 0, HEIGHT - PADDLE_H)

        ball.x += vx
        ball.y += vy
        if ball.top <= 0 or ball.bottom >= HEIGHT:
            vy *= -1
        if ball.colliderect(left) and vx < 0:
            vx *= -1
            ball.left = left.right
        if ball.colliderect(right) and vx > 0:
            vx *= -1
            ball.right = right.left
        if ball.left <= 0:
            score[1] += 1
            ball.center = (WIDTH // 2, HEIGHT // 2)
            vx, vy = 5, 4
        if ball.right >= WIDTH:
            score[0] += 1
            ball.center = (WIDTH // 2, HEIGHT // 2)
            vx, vy = -5, 4

        screen.fill((18, 18, 28))
        pygame.draw.rect(screen, (220, 220, 220), left)
        pygame.draw.rect(screen, (220, 220, 220), right)
        pygame.draw.ellipse(screen, (255, 200, 80), ball)
        pygame.draw.line(screen, (60, 60, 80), (WIDTH // 2, 0), (WIDTH // 2, HEIGHT), 2)
        text = font.render(f"{score[0]}    {score[1]}", True, (240, 240, 240))
        screen.blit(text, text.get_rect(center=(WIDTH // 2, 40)))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
