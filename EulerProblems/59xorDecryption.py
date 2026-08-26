"""Project Euler Problem 59: XOR Decryption"""

from pathlib import Path

COMMON = set(range(32, 127))


def score(data: bytes) -> int:
    return sum(1 for byte in data if byte in COMMON)


def solve() -> int:
    cipher_file = Path(__file__).with_name("cipher1.txt")
    if not cipher_file.exists():
        raise FileNotFoundError("Download cipher1.txt from Project Euler and place it in EulerProblems/")

    numbers = list(map(int, cipher_file.read_text().split(",")))
    best_sum = 0

    for a in range(97, 123):
        for b in range(97, 123):
            for c in range(97, 123):
                key = [a, b, c]
                decoded = bytes(numbers[i] ^ key[i % 3] for i in range(len(numbers)))
                if score(decoded) > score(bytes([best_sum % 256])) or best_sum == 0:
                    if score(decoded) >= len(numbers) * 0.95:
                        best_sum = sum(decoded)

    return best_sum


if __name__ == "__main__":
    print(solve())
