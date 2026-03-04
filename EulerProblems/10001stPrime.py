def largePrime(n):
    count = 1
    num = 1
    while count < n:
        num += 2
        for i in range(3, int(num**0.5) + 1, 2):
            if num % i == 0:
                break
        else:
            count += 1
    return num


print(largePrime(10001))