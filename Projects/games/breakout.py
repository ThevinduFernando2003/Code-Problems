"""Brick breaker. Left/Right move paddle, Space launch ball."""

import pygame

WIDTH, HEIGHT = 720, 520


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Breakout")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        paddle = pygame.Rect(WIDTH // 2 - 50, HEIGHT - 40, 100, 14)
        ball = pygame.Rect(WIDTH // 2 - 7, HEIGHT - 60, 14, 14)
        bricks = [pygame.Rect(20 + c * 70, 40 + r * 28, 64, 22) for r in range(5) for c in range(10)]
        return paddle, ball, -4, -5, bricks, False, False, 0

    paddle, ball, vx, vy, bricks, started, dead, score = reset()
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    paddle, ball, vx, vy, bricks, started, dead, score = reset()
                if event.key == pygame.K_SPACE:
                    started = True

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            paddle.x -= 8
        if keys[pygame.K_RIGHT]:
            paddle.x += 8
        paddle.x = max(0, min(WIDTH - paddle.w, paddle.x))

        if started and not dead:
            ball.x += vx
            ball.y += vy
            if ball.left <= 0 or ball.right >= WIDTH:
                vx *= -1
            if ball.top <= 0:
                vy *= -1
            if ball.colliderect(paddle) and vy > 0:
                vy *= -1
                offset = (ball.centerx - paddle.centerx) / (paddle.w / 2)
                vx = int(offset * 6) or vx
            for brick in bricks[:]:
                if ball.colliderect(brick):
                    bricks.remove(brick)
                    vy *= -1
                    score += 10
                    break
            if ball.top > HEIGHT:
                dead = True

        screen.fill((18, 18, 28))
        pygame.draw.rect(screen, (220, 220, 230), paddle)
        pygame.draw.ellipse(screen, (255, 200, 80), ball)
        colors = [(220, 80, 80), (230, 140, 60), (230, 200, 70), (90, 190, 90), (80, 140, 220)]
        for i, brick in enumerate(bricks):
            pygame.draw.rect(screen, colors[(brick.y // 28) % len(colors)], brick)
        screen.blit(font.render(f"Score {score}   Space serve", True, (240, 240, 240)), (16, 8))
        if dead:
            screen.blit(font.render("Missed  R restart", True, (255, 180, 120)), (250, 250))
        if not bricks:
            screen.blit(font.render("Cleared the wall!", True, (160, 230, 160)), (240, 250))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
