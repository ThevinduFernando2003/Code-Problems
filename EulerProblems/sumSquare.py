def sumSquare(n):
    total = 0
    for i in range(1, n + 1):
        total += i**2
    return total


def squareSum(n):
    total = 0
    for i in range(1, n + 1):
        total += i
    return total**2


def difference(n):
    return squareSum(n) - sumSquare(n)


if __name__ == "__main__":
    print(difference(100))  # 25164150
