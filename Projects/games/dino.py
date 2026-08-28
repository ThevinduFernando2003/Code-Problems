"""Chrome Dino style runner. Space or Up to jump."""

import random
import pygame

WIDTH, HEIGHT = 800, 360
GROUND = 280


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Dino")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 24)

    def reset():
        dino = pygame.Rect(80, GROUND - 44, 36, 44)
        return dino, 0, [], 0, False, 0

    dino, vy, cactus, score, dead, spawn = reset()
    running = True

    while running:
        jump = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    dino, vy, cactus, score, dead, spawn = reset()
                if event.key in (pygame.K_SPACE, pygame.K_UP):
                    jump = True

        if not dead:
            on_ground = dino.bottom >= GROUND
            if jump and on_ground:
                vy = -13
            vy += 0.7
            dino.y += int(vy)
            if dino.bottom > GROUND:
                dino.bottom = GROUND
                vy = 0
            spawn += 1
            if spawn > 70 + random.randint(0, 40):
                spawn = 0
                cactus.append(pygame.Rect(WIDTH, GROUND - 40, 18, 40))
            for c in cactus:
                c.x -= 8
            cactus[:] = [c for c in cactus if c.right > 0]
            if any(dino.colliderect(c) for c in cactus):
                dead = True
            score += 1

        screen.fill((245, 245, 240))
        pygame.draw.line(screen, (40, 40, 40), (0, GROUND), (WIDTH, GROUND), 3)
        pygame.draw.rect(screen, (60, 60, 70), dino)
        pygame.draw.circle(screen, (20, 20, 20), (dino.right - 8, dino.top + 12), 3)
        for c in cactus:
            pygame.draw.rect(screen, (40, 130, 60), c)
        screen.blit(font.render(f"Score {score // 5}", True, (20, 20, 20)), (20, 16))
        if dead:
            msg = font.render("Crashed  R restart", True, (160, 30, 30))
            screen.blit(msg, (WIDTH // 2 - 110, 80))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
