"""Two-player chess. Click a piece, then a legal square. White moves first."""

import pygame

SIZE = 72
MARGIN = 24
WIDTH = MARGIN * 2 + SIZE * 8
HEIGHT = MARGIN * 2 + SIZE * 8 + 36
WHITE_PIECES = "PNBRQK"
BLACK_PIECES = "pnbrqk"
GLYPH = {
    "K": "K",
    "Q": "Q",
    "R": "R",
    "B": "B",
    "N": "N",
    "P": "P",
    "k": "k",
    "q": "q",
    "r": "r",
    "b": "b",
    "n": "n",
    "p": "p",
}


def start_board():
    return [
        list("rnbqkbnr"),
        list("pppppppp"),
        list("........"),
        list("........"),
        list("........"),
        list("........"),
        list("PPPPPPPP"),
        list("RNBQKBNR"),
    ]


def inside(r, c):
    return 0 <= r < 8 and 0 <= c < 8


def color_of(piece):
    if piece in WHITE_PIECES:
        return "w"
    if piece in BLACK_PIECES:
        return "b"
    return None


def find_king(board, side):
    target = "K" if side == "w" else "k"
    for r in range(8):
        for c in range(8):
            if board[r][c] == target:
                return r, c
    return None


def ray_moves(board, r, c, side, dirs):
    moves = []
    for dr, dc in dirs:
        nr, nc = r + dr, c + dc
        while inside(nr, nc):
            cell = board[nr][nc]
            if cell == ".":
                moves.append((nr, nc))
            else:
                if color_of(cell) != side:
                    moves.append((nr, nc))
                break
            nr += dr
            nc += dc
    return moves


def piece_moves(board, r, c):
    piece = board[r][c]
    side = color_of(piece)
    moves = []
    if piece in "Pp":
        step = -1 if piece == "P" else 1
        start = 6 if piece == "P" else 1
        if inside(r + step, c) and board[r + step][c] == ".":
            moves.append((r + step, c))
            if r == start and board[r + 2 * step][c] == ".":
                moves.append((r + 2 * step, c))
        for dc in (-1, 1):
            nr, nc = r + step, c + dc
            if inside(nr, nc) and color_of(board[nr][nc]) and color_of(board[nr][nc]) != side:
                moves.append((nr, nc))
    elif piece in "Nn":
        for dr, dc in ((-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)):
            nr, nc = r + dr, c + dc
            if inside(nr, nc) and color_of(board[nr][nc]) != side:
                moves.append((nr, nc))
    elif piece in "Bb":
        moves.extend(ray_moves(board, r, c, side, ((-1, -1), (-1, 1), (1, -1), (1, 1))))
    elif piece in "Rr":
        moves.extend(ray_moves(board, r, c, side, ((-1, 0), (1, 0), (0, -1), (0, 1))))
    elif piece in "Qq":
        moves.extend(
            ray_moves(
                board,
                r,
                c,
                side,
                ((-1, -1), (-1, 1), (1, -1), (1, 1), (-1, 0), (1, 0), (0, -1), (0, 1)),
            )
        )
    elif piece in "Kk":
        for dr in (-1, 0, 1):
            for dc in (-1, 0, 1):
                if dr == dc == 0:
                    continue
                nr, nc = r + dr, c + dc
                if inside(nr, nc) and color_of(board[nr][nc]) != side:
                    moves.append((nr, nc))
    return moves


def in_check(board, side):
    king = find_king(board, side)
    if king is None:
        return True
    enemy = "b" if side == "w" else "w"
    for r in range(8):
        for c in range(8):
            if color_of(board[r][c]) == enemy:
                if king in piece_moves(board, r, c):
                    return True
    return False


def legal_moves(board, r, c):
    side = color_of(board[r][c])
    result = []
    for nr, nc in piece_moves(board, r, c):
        saved_from, saved_to = board[r][c], board[nr][nc]
        board[nr][nc] = board[r][c]
        board[r][c] = "."
        if (board[nr][nc] in "Pp") and nr in (0, 7):
            board[nr][nc] = "Q" if saved_from == "P" else "q"
        if not in_check(board, side):
            result.append((nr, nc))
        board[r][c], board[nr][nc] = saved_from, saved_to
    return result


def has_any_move(board, side):
    for r in range(8):
        for c in range(8):
            if color_of(board[r][c]) == side and legal_moves(board, r, c):
                return True
    return False


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Chess")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 40)
    small = pygame.font.SysFont("consolas", 20)
    board = start_board()
    turn = "w"
    selected = None
    options = []
    status = "White to move"
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                if event.key == pygame.K_r:
                    board = start_board()
                    turn, selected, options = "w", None, []
                    status = "White to move"
            if event.type == pygame.MOUSEBUTTONDOWN:
                mx, my = event.pos
                c = (mx - MARGIN) // SIZE
                r = (my - MARGIN) // SIZE
                if not inside(r, c):
                    continue
                if selected and (r, c) in options:
                    piece = board[selected[0]][selected[1]]
                    board[r][c] = piece
                    board[selected[0]][selected[1]] = "."
                    if piece == "P" and r == 0:
                        board[r][c] = "Q"
                    if piece == "p" and r == 7:
                        board[r][c] = "q"
                    turn = "b" if turn == "w" else "w"
                    selected, options = None, []
                    if in_check(board, turn) and not has_any_move(board, turn):
                        winner = "White" if turn == "b" else "Black"
                        status = f"Checkmate  {winner} wins  R restart"
                    elif not has_any_move(board, turn):
                        status = "Stalemate  R restart"
                    elif in_check(board, turn):
                        status = ("White" if turn == "w" else "Black") + " in check"
                    else:
                        status = ("White" if turn == "w" else "Black") + " to move"
                elif color_of(board[r][c]) == turn:
                    selected = (r, c)
                    options = legal_moves(board, r, c)
                else:
                    selected, options = None, []

        screen.fill((32, 28, 24))
        for r in range(8):
            for c in range(8):
                light = (r + c) % 2 == 0
                color = (238, 216, 176) if light else (180, 124, 74)
                rect = pygame.Rect(MARGIN + c * SIZE, MARGIN + r * SIZE, SIZE, SIZE)
                pygame.draw.rect(screen, color, rect)
                if selected == (r, c):
                    pygame.draw.rect(screen, (250, 220, 80), rect, 4)
                if (r, c) in options:
                    pygame.draw.circle(screen, (40, 140, 70), rect.center, 10)
                piece = board[r][c]
                if piece != ".":
                    shade = (20, 20, 20) if piece in WHITE_PIECES else (10, 10, 40)
                    fill = (250, 250, 250) if piece in WHITE_PIECES else (40, 40, 50)
                    glyph = font.render(GLYPH[piece], True, fill)
                    outline = font.render(GLYPH[piece], True, shade)
                    pos = glyph.get_rect(center=rect.center)
                    screen.blit(outline, pos.move(1, 1))
                    screen.blit(glyph, pos)
        screen.blit(small.render(status + "   click piece then square", True, (240, 230, 210)), (MARGIN, HEIGHT - 30))
        pygame.display.flip()
        clock.tick(30)

    pygame.quit()


if __name__ == "__main__":
    main()
