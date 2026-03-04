def merge_and_count(arr, temp, left, mid, right):
    
    i = left     # Left subarray index
    j = mid + 1  # Right subarray index
    k = left     # Merged array index
    inv_count = 0  # Count of inversions

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:  # No inversion
            temp[k] = arr[i]
            i += 1
        else:  # Inversion found
            temp[k] = arr[j]
            inv_count += (mid - i + 1)  # All remaining elements in left part are greater
            j += 1
        k += 1

    # Copy remaining elements from left subarray
    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    # Copy remaining elements from right subarray
    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    # Copy sorted elements back into original array
    for i in range(left, right + 1):
        arr[i] = temp[i]

    return inv_count

def merge_sort_and_count(arr, temp, left, right):
    inv_count = 0
    if left < right:
        mid = (left + right) // 2  # Find the middle point

        inv_count += merge_sort_and_count(arr, temp, left, mid)  # Count inversions in left half
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right)  # Count in right half
        inv_count += merge_and_count(arr, temp, left, mid, right)  # Count split inversions

    return inv_count

def count_inversions(arr):
    n = len(arr)
    temp = [0] * n  # Temporary array for merge sort
    return merge_sort_and_count(arr, temp, 0, n - 1)

# Read input
n = int(input())  # Number of warriors
arr = list(map(int, input().split()))  # Warrior rankings

# Compute and print the number of misplaced pairs
print(count_inversions(arr))
