"""Bouncing ball demo. Watch the ball bounce; click to add more."""

import random
import pygame

WIDTH, HEIGHT = 720, 480


class Ball:
    def __init__(self):
        self.x = random.randint(40, WIDTH - 40)
        self.y = random.randint(40, HEIGHT - 40)
        self.vx = random.choice([-5, -4, 4, 5])
        self.vy = random.choice([-5, -4, 4, 5])
        self.r = random.randint(12, 24)
        self.color = (random.randint(80, 255), random.randint(80, 255), random.randint(80, 255))

    def update(self):
        self.x += self.vx
        self.y += self.vy
        if self.x - self.r < 0 or self.x + self.r > WIDTH:
            self.vx *= -1
        if self.y - self.r < 0 or self.y + self.r > HEIGHT:
            self.vy *= -1

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (int(self.x), int(self.y)), self.r)


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Bouncing Ball")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 20)
    balls = [Ball()]
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                balls.append(Ball())

        for ball in balls:
            ball.update()

        screen.fill((16, 16, 24))
        for ball in balls:
            ball.draw(screen)
        screen.blit(font.render("Click to add balls", True, (200, 200, 210)), (16, 16))
        pygame.display.flip()
        clock.tick(60)

    pygame.quit()


if __name__ == "__main__":
    main()
