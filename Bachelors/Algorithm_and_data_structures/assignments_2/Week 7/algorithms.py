def lomutoPartition(arr:int, low:int, high:int) -> int:
    pivot = arr[low]
    i = low 

    for j in range(low+1, high+1):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[low], arr[i] = arr[i], arr[low]

    return i

def hoarePartion(arr:int, low:int, high:int) -> int:
    pivot = arr[low]
    i = low - 1
    j =  high + 1

    while True:
        while (arr[i] < pivot):
            i += 1

        while (arr[j] > pivot):
            j -= 1

        if (i >= j):
            return j
        
        arr[i], arr[j] = arr[j], arr[i]

def medianOfThree(arr:int, low:int, high:int) -> int:
    mid = low + (high - low) // 2 

    if arr[low] > arr[mid]:
        arr[low], arr[mid] = arr[mid], arr[low]

    if arr[low] > arr[high]:
        arr[low], arr[high] = arr[high], arr[low]
    
    if arr[mid] > arr[high]:
        arr[mid], arr[high] = arr[high], arr[mid]

    return arr[mid]


def medianThreePartion(arr:int, low:int, high:int) -> int:
    pivot = medianOfThree(arr, low, high)
    i = low - 1

    for j in range(low, high+1):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i+1], arr[high], arr[high], arr[i+1]

    return i+1

def quicksortL(arr:int, low:int, high:int) -> None:
    if low < high:

        # Find the partition index
        pi = lomutoPartition(arr, low, high)

        # Recursively sort the two subarrays
        quicksortL(arr, low, pi - 1)
        quicksortL(arr, pi + 1, high)

def quicksortH(arr:int, low:int, high:int) -> None:
    if low < high:
        pi = hoarePartion(arr, low, high)
        quicksortH(arr, 0, pi)
        quicksortH(arr, pi+1, high)

def quicksortM(arr:int, low:int, high:int) -> None:
    if low < high:
        # Find the partition index
        pi = medianThreePartion(arr, low, high)

        # Recursively sort the two subarrays
        quicksortM(arr, low, pi - 1)
        quicksortM(arr, pi + 1, high)