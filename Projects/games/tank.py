"""Two-player tank duel. WASD+F vs Arrows+Enter."""

import pygame

WIDTH, HEIGHT = 800, 500
SPEED = 4
BULLET = 8


def bounce_walls(rect):
    rect.x = max(0, min(WIDTH - rect.w, rect.x))
    rect.y = max(0, min(HEIGHT - rect.h, rect.y))


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Tank")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 24)

    def reset():
        a = pygame.Rect(80, HEIGHT // 2, 36, 36)
        b = pygame.Rect(WIDTH - 116, HEIGHT // 2, 36, 36)
        return a, b, (1, 0), (-1, 0), [], 0, 0, False

    a, b, da, db, shots, sa, sb, over = reset()
    running = True

    while running:
        fire_a = fire_b = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    a, b, da, db, shots, sa, sb, over = reset()
                if event.key == pygame.K_f:
                    fire_a = True
                if event.key == pygame.K_RETURN:
                    fire_b = True

        keys = pygame.key.get_pressed()
        if not over:
            if keys[pygame.K_w]:
                a.y -= SPEED
                da = (0, -1)
            if keys[pygame.K_s]:
                a.y += SPEED
                da = (0, 1)
            if keys[pygame.K_a]:
                a.x -= SPEED
                da = (-1, 0)
            if keys[pygame.K_d]:
                a.x += SPEED
                da = (1, 0)
            if keys[pygame.K_UP]:
                b.y -= SPEED
                db = (0, -1)
            if keys[pygame.K_DOWN]:
                b.y += SPEED
                db = (0, 1)
            if keys[pygame.K_LEFT]:
                b.x -= SPEED
                db = (-1, 0)
            if keys[pygame.K_RIGHT]:
                b.x += SPEED
                db = (1, 0)
            bounce_walls(a)
            bounce_walls(b)
            if fire_a:
                shots.append(["a", pygame.Rect(a.centerx, a.centery, BULLET, BULLET), da])
            if fire_b:
                shots.append(["b", pygame.Rect(b.centerx, b.centery, BULLET, BULLET), db])
            for shot in shots:
                shot[1].x += shot[2][0] * 8
                shot[1].y += shot[2][1] * 8
            shots[:] = [s for s in shots if screen.get_rect().colliderect(s[1])]
            for owner, rect, _ in shots[:]:
                if owner == "a" and rect.colliderect(b):
                    sa += 1
                    over = True
                if owner == "b" and rect.colliderect(a):
                    sb += 1
                    over = True

        screen.fill((28, 40, 28))
        pygame.draw.rect(screen, (70, 160, 90), a)
        pygame.draw.rect(screen, (200, 90, 70), b)
        for _, rect, _ in shots:
            pygame.draw.rect(screen, (255, 230, 80), rect)
        screen.blit(font.render(f"Green {sa}   Red {sb}   R restart", True, (240, 240, 240)), (16, 12))
        if over:
            screen.blit(font.render("Hit! R for next round", True, (255, 220, 120)), (260, 220))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
