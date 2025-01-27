def mpartition(a, p, q):
    # Choose the first two elements as pivots
    pivot1 = a[p]
    pivot2 = a[p + 1]
    
    # Ensure pivot1 <= pivot2
    if pivot1 > pivot2:
        pivot1, pivot2 = pivot2, pivot1
    
    # Initialize pointers
    lt1 = p + 2  # Position for elements < pivot1
    lt2 = p + 2  # Position for elements between pivot1 and pivot2 (inclusive)
    gt = q + 1   # Position for elements > pivot2
    
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
    
    # Move pivot elements to their correct positions
    lt1 -= 1
    lt2 -= 1
    a[p], a[lt1] = a[lt1], a[p]
    a[p + 1], a[lt2] = a[lt2], a[p + 1]
    
    return lt1, lt2

# Example usage with mquicksort
def mquicksort(a, p, q):
    if p < q:
        pivot_1, pivot_2 = mpartition(a, p, q)
        mquicksort(a, p, pivot_1 - 1)
        mquicksort(a, pivot_1 + 1, pivot_2 - 1)
        mquicksort(a, pivot_2 + 1, q)
    return a

# Helper function to sort the entire array
def sort_array(arr):
    if len(arr) <= 1:
        return arr
    return mquicksort(arr, 0, len(arr) - 1)

# Example usage
arr = [3, 6, 8, 10, 1, 2, 1]
sorted_arr = sort_array(arr)
print("sorted arr is: \n")
print(sorted_arr)  # Output will be the sorted array
