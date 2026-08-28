"""Mini platformer. Arrows move, Space jump, reach the flag."""

import pygame

WIDTH, HEIGHT = 800, 450
GRAVITY = 0.7
JUMP = -13


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Mini Platformer")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 22)

    platforms = [
        pygame.Rect(0, 410, 800, 40),
        pygame.Rect(120, 330, 140, 18),
        pygame.Rect(320, 260, 140, 18),
        pygame.Rect(520, 190, 140, 18),
        pygame.Rect(680, 120, 100, 18),
    ]
    coins = [pygame.Rect(170, 300, 16, 16), pygame.Rect(370, 230, 16, 16), pygame.Rect(570, 160, 16, 16)]
    flag = pygame.Rect(730, 70, 16, 50)
    player = pygame.Rect(40, 360, 28, 42)
    vx = vy = 0
    score = 0
    won = False
    on_ground = True
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    player = pygame.Rect(40, 360, 28, 42)
                    coins = [
                        pygame.Rect(170, 300, 16, 16),
                        pygame.Rect(370, 230, 16, 16),
                        pygame.Rect(570, 160, 16, 16),
                    ]
                    vx = vy = score = 0
                    won = False
                if event.key == pygame.K_SPACE and on_ground:
                    vy = JUMP

        keys = pygame.key.get_pressed()
        vx = 0
        if not won:
            if keys[pygame.K_LEFT]:
                vx = -5
            if keys[pygame.K_RIGHT]:
                vx = 5
            vy += GRAVITY
            player.x += int(vx)
            player.x = max(0, min(WIDTH - player.w, player.x))
            dy = int(vy)
            if dy == 0 and vy > 0:
                dy = 1
            player.y += dy
            on_ground = False
            for plat in platforms:
                if player.colliderect(plat) and vy >= 0:
                    player.bottom = plat.top
                    vy = 0
                    on_ground = True
            if not on_ground and player.bottom > HEIGHT:
                player = pygame.Rect(40, 360, 28, 42)
                vy = 0
            for coin in coins[:]:
                if player.colliderect(coin):
                    coins.remove(coin)
                    score += 1
            if player.colliderect(flag):
                won = True

        screen.fill((120, 190, 255))
        for plat in platforms:
            pygame.draw.rect(screen, (90, 160, 70), plat)
        for coin in coins:
            pygame.draw.circle(screen, (255, 210, 40), coin.center, 8)
        pygame.draw.rect(screen, (220, 50, 50), flag)
        pygame.draw.rect(screen, (40, 90, 200), player, border_radius=6)
        msg = f"Coins {score}/3"
        if won:
            msg += "  Flag reached! R restart"
        screen.blit(font.render(msg, True, (20, 20, 30)), (16, 16))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
