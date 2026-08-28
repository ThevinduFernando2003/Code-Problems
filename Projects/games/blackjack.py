"""Blackjack. H hit, S stand, N new hand."""

import random
import pygame

SUITS = "CDHS"
RANKS = "A23456789TJQK"


def value(hand):
    total = 0
    aces = 0
    for card in hand:
        rank = card[0]
        if rank == "A":
            aces += 1
            total += 11
        elif rank in "TJQK":
            total += 10
        else:
            total += int(rank)
    while total > 21 and aces:
        total -= 10
        aces -= 1
    return total


def draw_text(screen, font, text, pos, color=(240, 240, 240)):
    screen.blit(font.render(text, True, color), pos)


def main():
    pygame.init()
    screen = pygame.display.set_mode((720, 480))
    pygame.display.set_caption("Blackjack")
    font = pygame.font.SysFont("consolas", 28)
    small = pygame.font.SysFont("consolas", 20)

    def deal():
        deck = [r + s for r in RANKS for s in SUITS]
        random.shuffle(deck)
        player = [deck.pop(), deck.pop()]
        dealer = [deck.pop(), deck.pop()]
        return deck, player, dealer, False, ""

    deck, player, dealer, done, message = deal()
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_n:
                    deck, player, dealer, done, message = deal()
                if not done and event.key == pygame.K_h:
                    player.append(deck.pop())
                    if value(player) > 21:
                        done, message = True, "Bust. Dealer wins."
                if not done and event.key == pygame.K_s:
                    while value(dealer) < 17:
                        dealer.append(deck.pop())
                    pv, dv = value(player), value(dealer)
                    if dv > 21 or pv > dv:
                        message = "You win"
                    elif pv == dv:
                        message = "Push"
                    else:
                        message = "Dealer wins"
                    done = True

        screen.fill((12, 70, 40))
        draw_text(screen, small, "H hit   S stand   N new hand", (20, 16))
        hidden = done or False
        dealer_show = " ".join(dealer) if done else f"{dealer[0]} ??"
        draw_text(screen, font, f"Dealer: {dealer_show}", (40, 120))
        if done:
            draw_text(screen, small, f"Dealer total {value(dealer)}", (40, 160), (220, 220, 160))
        draw_text(screen, font, f"You: {' '.join(player)}", (40, 240))
        draw_text(screen, small, f"Your total {value(player)}", (40, 280), (220, 220, 160))
        if message:
            draw_text(screen, font, message, (40, 360), (255, 220, 120))
        pygame.display.flip()

    pygame.quit()


if __name__ == "__main__":
    main()
