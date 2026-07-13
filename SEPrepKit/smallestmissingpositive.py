#!/bin/python3

def smallestMissingPositive(orderNumbers):
    n = len(orderNumbers)

    i = 0
    while i < n:
        value = orderNumbers[i]
        target_index = value - 1

        if 1 <= value <= n and orderNumbers[target_index] != value:
            orderNumbers[i], orderNumbers[target_index] = (
                orderNumbers[target_index],
                orderNumbers[i],
            )
        else:
            i += 1

    for index in range(n):
        if orderNumbers[index] != index + 1:
            return index + 1

    return n + 1


if __name__ == '__main__':
    order_count = int(input().strip())

    orderNumbers = []
    for _ in range(order_count):
        orderNumbers.append(int(input().strip()))

    result = smallestMissingPositive(orderNumbers)
    print(result)
