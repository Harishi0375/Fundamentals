def counting_sort(arr: list[int]) -> list[int]: 
	# Find the maximum element in the array
	max_element = max(arr)
	
	# Create a count array to store the count of each element 
	# array of zeros max element + 1 times
	count = [0] * (max_element + 1)
	# Count the occurrences of each element in the input array 
	for num in arr: 
		count[num] += 1 
		
	# Update the count array to store the cumulative count of each element 
	for i in range(1, len(count)): 
		count[i] += count[i - 1] 
		
	# Create a sorted array to store the result 
	sorted_arr = [0] * len(arr) 
	
	# Place each element at its correct position in the sorted array 
	# reverser to make the algorithm stable
	for num in reversed(arr): 
		sorted_arr[count[num] - 1] = num
		count[num] -= 1
	
	return sorted_arr


def insertion_sort(arr: list[int]) -> None:
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def bucket_sort(arr: list[int]) -> list[int]:
    # Find maximum and minimum values in the array
    max_val = max(arr)
    min_val = min(arr)
    
    # Calculate bucket size and number of buckets
    bucket_size = (max_val - min_val) / len(arr)
    bucket_count = len(arr) + 1
    
    # Create empty buckets
    buckets = [[] for _ in range(bucket_count)]
    
    # Put array elements into different buckets
    for num in arr:
        index = int((num - min_val) / bucket_size)
        buckets[index].append(num)
    
    # Sort individual buckets
    for i in range(bucket_count):
        insertion_sort(buckets[i])
    
    # Concatenate buckets
    result = []
    for bucket in buckets:
        result.extend(bucket)
    
    return result


def counting_sort_string(arr: list[str], exp: int) -> None:
    n = len(arr)
    output = [0] * n
    count = [0] * 256  # 256 possible characters in ASCII

    for i in range(n):
        index = ord(arr[i][exp]) if exp < len(arr[i]) else 0
        count[index] += 1

    for i in range(1, 256):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = ord(arr[i][exp]) if exp < len(arr[i]) else 0
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]


def radix_sort_string(arr: list[str]) -> None:
    max_length = max(len(word) for word in arr)
    for exp in range(max_length - 1, -1, -1):
        counting_sort_string(arr, exp)


def counting_sort_radix(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10  
    
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    
    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr: list[int]) -> None:
    max_val = max(arr)
    exp = 1

    
    while max_val // exp > 0:
        counting_sort_radix(arr, exp)
        exp *= 10