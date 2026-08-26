from collections import deque
from math import isqrt, gcd

# 79
keylog = ["319", "680", "180", "690", "486", "486", "960", "220", "737", "870", "713", "713"]
start = tuple(0 for _ in keylog)
queue = deque([(start, "")])
seen = {start}
while queue:
    state, string = queue.popleft()
    if all(state[i] == len(keylog[i]) for i in range(len(keylog))):
        print("79:", string)
        break
    for digit in "0123456789":
        new_state = list(state)
        for i, attempt in enumerate(keylog):
            if new_state[i] < len(attempt) and attempt[new_state[i]] == digit:
                new_state[i] += 1
        new_state = tuple(new_state)
        if new_state not in seen:
            seen.add(new_state)
            queue.append((new_state, string + digit))

# 80
def sqrt_digit_sum(number: int, digits: int = 100) -> int:
    root = isqrt(number)
    remainder = number - root * root
    total = 0
    for _ in range(digits):
        remainder *= 100
        digit = 9
        while (20 * root + digit) * digit > remainder:
            digit -= 1
        remainder -= (20 * root + digit) * digit
        root = root * 10 + digit
        total += digit
    return total

print("80 sqrt2:", sqrt_digit_sum(2))
print(
    "80 total:",
    sum(sqrt_digit_sum(n) for n in range(1, 101) if isqrt(n) * isqrt(n) != n),
)

# 91
def is_right(x1, y1, x2, y2):
    a = x1 * x1 + y1 * y1
    b = x2 * x2 + y2 * y2
    c = (x2 - x1) ** 2 + (y2 - y1) ** 2
    return a + b == c or b + c == a or c + a == b

print(
    "91:",
    sum(
        1
        for x1 in range(51)
        for y1 in range(51)
        for x2 in range(51)
        for y2 in range(51)
        if y2 * x1 < y1 * x2 and is_right(x1, y1, x2, y2)
    ),
)

# 86
for m in range(6, 2500):
    count = 0
    for c in range(1, m // 3 + 1):
        for b in range(c, (m - c) // 2 + 1):
            for a in range(b, m - b - c + 1):
                shortest = min((a + b) ** 2 + c * c, (a + c) ** 2 + b * b, (b + c) ** 2 + a * a)
                root = isqrt(shortest)
                if root * root == shortest:
                    count += 1
    if count > 1000:
        print("86:", m, count)
        break

# 94
def is_square(value: int) -> bool:
    root = isqrt(value)
    return root * root == value

total = 0
side = 1
b = 1
parity = 1
while True:
    perimeter = 3 * side + (1 if parity == 0 else -1)
    if perimeter > 1_000_000_000:
        break
    if parity == 0:
        area_squared = (3 * side + 1) * (side + 1) * (side + 1) * (side - 1)
    else:
        area_squared = (3 * side - 1) * (side - 1) * (side - 1) * (side + 1)
    if area_squared % 16 == 0 and is_square(area_squared // 16):
        total += perimeter
    side, b, parity = 4 * side - b + 2 * parity, side + b, (side + b) // 2 - parity
print("94:", total)

# 100
x = 3
y = 1
while True:
    root = isqrt(8 * y * y + 1)
    if root % 2 == 1:
        blue = (root + 1) // 2 + y
        if blue + y > 10**12:
            print("100:", blue)
            break
    x, y = x * 3 + y * 8, x + y * 3
