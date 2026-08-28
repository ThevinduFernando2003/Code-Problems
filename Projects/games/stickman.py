"""Stickman runner. Space jump, avoid incoming obstacles."""

import random
import pygame

WIDTH, HEIGHT = 800, 360
GROUND = 280


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Stickman")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        return pygame.Rect(120, GROUND - 70, 28, 70), 0, [], 0, False, 0

    player, vy, obstacles, score, dead, spawn = reset()
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
                    player, vy, obstacles, score, dead, spawn = reset()
                if event.key in (pygame.K_SPACE, pygame.K_UP):
                    jump = True

        if not dead:
            if jump and player.bottom >= GROUND:
                vy = -15
            vy += 0.8
            player.y += int(vy)
            if player.bottom >= GROUND:
                player.bottom = GROUND
                vy = 0
            spawn += 1
            if spawn > 70:
                spawn = 0
                h = random.choice([36, 50, 70])
                obstacles.append(pygame.Rect(WIDTH + 10, GROUND - h, 28, h))
            for ob in obstacles:
                ob.x -= 8
            obstacles[:] = [o for o in obstacles if o.right > 0]
            if any(player.colliderect(o) for o in obstacles):
                dead = True
            score += 1

        screen.fill((210, 230, 245))
        pygame.draw.rect(screen, (70, 140, 70), (0, GROUND, WIDTH, HEIGHT - GROUND))
        cx, cy = player.centerx, player.top + 12
        pygame.draw.circle(screen, (30, 30, 30), (cx, cy), 10, 2)
        pygame.draw.line(screen, (30, 30, 30), (cx, cy + 10), (cx, player.bottom - 22), 2)
        pygame.draw.line(screen, (30, 30, 30), (cx, cy + 22), (player.left, cy + 36), 2)
        pygame.draw.line(screen, (30, 30, 30), (cx, cy + 22), (player.right, cy + 36), 2)
        pygame.draw.line(screen, (30, 30, 30), (cx, player.bottom - 22), (player.left, player.bottom), 2)
        pygame.draw.line(screen, (30, 30, 30), (cx, player.bottom - 22), (player.right, player.bottom), 2)
        for ob in obstacles:
            pygame.draw.rect(screen, (160, 70, 50), ob)
        screen.blit(font.render(f"Score {score // 10}", True, (20, 20, 20)), (16, 16))
        if dead:
            screen.blit(font.render("Ouch  R restart", True, (40, 40, 40)), (300, 80))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
