"""Traffic racer. Left/Right to dodge cars. Survive and score."""

import random
import pygame

WIDTH, HEIGHT = 400, 640
LANES = [80, 175, 270]


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Traffic Racer")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        player = pygame.Rect(LANES[1], 520, 50, 80)
        return player, 1, [], 0, False, 0

    player, lane, cars, score, dead, spawn = reset()
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    player, lane, cars, score, dead, spawn = reset()
                if not dead and event.key == pygame.K_LEFT:
                    lane = max(0, lane - 1)
                    player.x = LANES[lane]
                if not dead and event.key == pygame.K_RIGHT:
                    lane = min(2, lane + 1)
                    player.x = LANES[lane]

        if not dead:
            spawn += 1
            if spawn > 40:
                spawn = 0
                cars.append(pygame.Rect(random.choice(LANES), -90, 50, 80))
            for car in cars:
                car.y += 7
            cars[:] = [c for c in cars if c.top < HEIGHT]
            if any(player.colliderect(c) for c in cars):
                dead = True
            score += 1

        screen.fill((40, 40, 48))
        pygame.draw.rect(screen, (60, 60, 70), (50, 0, 300, HEIGHT))
        for y in range(0, HEIGHT, 40):
            pygame.draw.rect(screen, (220, 220, 220), (WIDTH // 2 - 4, y, 8, 20))
        pygame.draw.rect(screen, (70, 170, 255), player, border_radius=8)
        for car in cars:
            pygame.draw.rect(screen, (220, 80, 80), car, border_radius=8)
        screen.blit(font.render(f"Score {score // 10}", True, (240, 240, 240)), (16, 16))
        if dead:
            screen.blit(font.render("Crash  R restart", True, (255, 200, 120)), (110, 300))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
