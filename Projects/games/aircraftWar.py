"""Aircraft war. Arrows move, Space shoot. Destroy incoming ships."""

import random
import pygame

WIDTH, HEIGHT = 480, 640


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Aircraft War")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    def reset():
        player = pygame.Rect(WIDTH // 2 - 15, HEIGHT - 70, 30, 30)
        return player, [], [], 0, False, 0

    player, bullets, enemies, score, dead, spawn = reset()
    running = True

    while running:
        shoot = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    player, bullets, enemies, score, dead, spawn = reset()
                if event.key == pygame.K_SPACE:
                    shoot = True

        keys = pygame.key.get_pressed()
        if not dead:
            if keys[pygame.K_LEFT]:
                player.x -= 6
            if keys[pygame.K_RIGHT]:
                player.x += 6
            if keys[pygame.K_UP]:
                player.y -= 6
            if keys[pygame.K_DOWN]:
                player.y += 6
            player.clamp_ip(screen.get_rect())
            if shoot:
                bullets.append(pygame.Rect(player.centerx - 3, player.top - 12, 6, 12))
            for b in bullets:
                b.y -= 10
            bullets[:] = [b for b in bullets if b.bottom > 0]
            spawn += 1
            if spawn > 35:
                spawn = 0
                enemies.append(pygame.Rect(random.randint(20, WIDTH - 40), -30, 28, 28))
            for e in enemies:
                e.y += 4
            enemies[:] = [e for e in enemies if e.top < HEIGHT]
            for b in bullets[:]:
                for e in enemies[:]:
                    if b.colliderect(e):
                        bullets.remove(b)
                        enemies.remove(e)
                        score += 10
                        break
            if any(player.colliderect(e) for e in enemies):
                dead = True

        screen.fill((8, 12, 28))
        pygame.draw.polygon(screen, (90, 200, 255), [player.midtop, player.bottomleft, player.bottomright])
        for b in bullets:
            pygame.draw.rect(screen, (255, 230, 80), b)
        for e in enemies:
            pygame.draw.rect(screen, (220, 80, 90), e)
        screen.blit(font.render(f"Score {score}", True, (230, 230, 240)), (12, 12))
        if dead:
            screen.blit(font.render("Hit  R restart", True, (255, 200, 120)), (160, 300))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
