def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def summPrime(n):
    total = 0
    for num in range(2,n):
        if isPrime(num):
            total += num
    return total

print(summPrime(2000000))
