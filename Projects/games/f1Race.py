"""F1-style road racer. Left/Right to change lanes, survive traffic."""

import random
import pygame

WIDTH, HEIGHT = 480, 640
LANES = [90, 190, 290, 390]


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("F1 Race")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        return 1, pygame.Rect(LANES[1], 500, 48, 86), [], 0, False, 0, 8

    lane, player, cars, score, dead, spawn, speed = reset()
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    lane, player, cars, score, dead, spawn, speed = reset()
                    player.x = LANES[lane]
                if not dead and event.key == pygame.K_LEFT:
                    lane = max(0, lane - 1)
                    player.x = LANES[lane]
                if not dead and event.key == pygame.K_RIGHT:
                    lane = min(3, lane + 1)
                    player.x = LANES[lane]

        if not dead:
            spawn += 1
            speed = 8 + score // 400
            if spawn > max(18, 50 - score // 200):
                spawn = 0
                cars.append(pygame.Rect(random.choice(LANES), -100, 48, 86))
            for car in cars:
                car.y += speed
            cars[:] = [c for c in cars if c.top < HEIGHT]
            if any(player.colliderect(c) for c in cars):
                dead = True
            score += 1

        screen.fill((18, 90, 40))
        pygame.draw.rect(screen, (50, 50, 58), (60, 0, 360, HEIGHT))
        offset = (score * 4) % 50
        for y in range(-50, HEIGHT, 50):
            pygame.draw.rect(screen, (240, 240, 240), (WIDTH // 2 - 4, y + offset, 8, 24))
        pygame.draw.rect(screen, (230, 50, 50), player, border_radius=10)
        for car in cars:
            pygame.draw.rect(screen, (40, 80, 200), car, border_radius=10)
        screen.blit(font.render(f"Lap score {score // 10}", True, (250, 250, 250)), (16, 16))
        if dead:
            screen.blit(font.render("Crash  R restart", True, (255, 220, 120)), (140, 300))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
