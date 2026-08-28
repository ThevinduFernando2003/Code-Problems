"""Flappy-style side scroller. Space or click to flap."""

import random
import pygame

WIDTH, HEIGHT = 480, 640


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Flappy Bird")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 28)

    def reset():
        bird = pygame.Rect(80, HEIGHT // 2, 28, 28)
        pipes = []
        return bird, 0, pipes, 0, False, 0

    bird, vy, pipes, score, dead, spawn = reset()
    gap = 160
    running = True

    while running:
        flap = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    bird, vy, pipes, score, dead, spawn = reset()
                if event.key == pygame.K_SPACE:
                    flap = True
            if event.type == pygame.MOUSEBUTTONDOWN:
                flap = True

        if not dead:
            if flap:
                vy = -8
            vy += 0.45
            bird.y += int(vy)
            spawn += 1
            if spawn % 90 == 0:
                top = random.randint(80, HEIGHT - gap - 80)
                pipes.append([WIDTH, top, False])
            for pipe in pipes:
                pipe[0] -= 4
            pipes[:] = [p for p in pipes if p[0] > -70]
            if bird.top < 0 or bird.bottom > HEIGHT:
                dead = True
            for x, top, counted in pipes:
                upper = pygame.Rect(x, 0, 60, top)
                lower = pygame.Rect(x, top + gap, 60, HEIGHT)
                if bird.colliderect(upper) or bird.colliderect(lower):
                    dead = True
                if not counted and x + 60 < bird.left:
                    pipe[2] = True
                    score += 1

        screen.fill((110, 190, 230))
        pygame.draw.rect(screen, (70, 170, 80), (0, HEIGHT - 40, WIDTH, 40))
        pygame.draw.ellipse(screen, (255, 220, 70), bird)
        for x, top, _ in pipes:
            pygame.draw.rect(screen, (50, 160, 70), (x, 0, 60, top))
            pygame.draw.rect(screen, (50, 160, 70), (x, top + gap, 60, HEIGHT))
        screen.blit(font.render(f"Score {score}", True, (20, 20, 20)), (16, 16))
        if dead:
            msg = font.render("Game over  R restart", True, (20, 20, 20))
            screen.blit(msg, msg.get_rect(center=(WIDTH // 2, HEIGHT // 2)))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
