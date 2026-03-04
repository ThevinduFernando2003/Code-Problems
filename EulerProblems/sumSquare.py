def sumSquare(n):
    sum = 0
    for i in range(1, n+1):
        sum += i**2
    return sum

def squareSum(n):
    sum = 0
    for i in range(1, n+1):
        sum += i
    return sum**2

print(squareSum(100) - sumSquare(100))