import random

def randomized_mpartition(a, p, q):
    # Randomly select two distinct pivots from the range [p, q]
    idx1, idx2 = random.sample(range(p, q + 1), 2)
    pivot1 = a[idx1]
    pivot2 = a[idx2]
    
    # Ensure pivot1 <= pivot2 for correctness
    if pivot1 > pivot2:
        pivot1, pivot2 = pivot2, pivot1

    # Move pivots to the start
    a[p], a[idx1] = a[idx1], a[p]
    a[p + 1], a[idx2] = a[idx2], a[p + 1]
    
    # Initialize pointers for partitioning
    lt1 = p + 2  # Next position for elements < pivot1
    lt2 = p + 2  # Next position for elements between pivot1 and pivot2
    gt = q + 1   # Next position for elements > pivot2

    i = p + 2
    while i < gt:
        if a[i] < pivot1:
            a[i], a[lt1] = a[lt1], a[i]
            lt1 += 1
            lt2 += 1
        elif a[i] <= pivot2:
            a[i], a[lt2] = a[lt2], a[i]
            lt2 += 1
        else:
            gt -= 1
            a[i], a[gt] = a[gt], a[i]
            continue
        i += 1

    # Move pivots to their final positions
    lt1 -= 1
    lt2 -= 1
    a[p], a[lt1] = a[lt1], a[p]
    a[p + 1], a[lt2] = a[lt2], a[p + 1]

    return lt1, lt2

def randomized_quicksort(a, p, q):
    if p < q:
        pivot1, pivot2 = randomized_mpartition(a, p, q)
        randomized_quicksort(a, p, pivot1 - 1)
        randomized_quicksort(a, pivot1 + 1, pivot2 - 1)
        randomized_quicksort(a, pivot2 + 1, q)
    return a

# Helper function to sort the entire array
def sort_array(arr):
    if len(arr) <= 1:
        return arr
    return randomized_quicksort(arr, 0, len(arr) - 1)

# Example usage
arr = [3, 6, 8, 10, 1, 2, 1]
sorted_arr = sort_array(arr)
print(sorted_arr)  # Output will be the sorted array
