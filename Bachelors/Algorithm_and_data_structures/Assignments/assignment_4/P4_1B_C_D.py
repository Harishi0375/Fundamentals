#code in python 
import random
import time

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    
    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]
    
    i = j = 0
    k = left
    
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, k):
    n = len(arr)
    for i in range(0, n, k):
        left = i
        right = min(i + k - 1, n - 1)
        insertion_sort(arr[left:right + 1])
    
    sz = k
    while sz < n:
        for left in range(0, n - 1, 2 * sz):
            mid = left + sz - 1
            right = min(left + 2 * sz - 1, n - 1)
            merge(arr, left, mid, right)
        sz *= 2

def measure_execution_time(arr, k):
    start_time = time.time()
    temp = arr[:]
    merge_sort(temp, k)
    end_time = time.time()
    return (end_time - start_time) * 1000

def generate_random_data(size):
    return [random.randint(1, 1000) for _ in range(size)]

if __name__ == "__main__":
    sizes = [1000, 5000, 10000]
    ks = [2, 5, 10]
    
    for size in sizes:
        print("Sequence size:", size)
        data = generate_random_data(size)
        for k in ks:
            print("k =", k, end=": ")
            execution_time = measure_execution_time(data, k)
            print("Execution time: {:.6f} ms".format(execution_time))
        print()


#ANSWER TO PART C 
# In this variant of Merge Sort, the choice of K significantly influences the algorithm's performance.
# For the best-case scenario, where the input is already sorted, smaller values of�k may lead to worse
# performance due to frequent switches between Merge Sort and Insertion Sort,
# whereas larger values of K can improve it by reducing these switches. In the average case, which 
# considers inputs with no specific pattern, the optimal�k value balances the overhead of Insertion 
# Sort on small subsequences with the benefits of reducing the number of recursive calls in Merge Sort. 
# However, regardless of K, the worst-case time complexity remains O(nlogn) when the input is reverse sorted,
# as the Merge Sort component dominates the overall complexity. Therefore, the choice of�k affects the best- and average-case
# time complexities but does not impact the worst-case scenario.
        

#ANSWER TO PART D
# In practice, choosing the optimal value of K involves balancing performance considerations between the best,
# average, and worst-case scenarios. One approach is to experiment with different values of K on representative 
# input data sets and measure the execution times. By analyzing the performance results, we can identify the value of
# K that minimizes the overall execution time across various scenarios. Additionally, considering the specific 
# characteristics of the input data (e.g., expected degree of presorting, typical data distribution) can help in selecting 
# an appropriate value of K that maximizes efficiency across different cases. Ultimately, the goal is to find a value
# of K that optimizes the trade-off between overhead from Insertion Sort and benefits from reduced recursive calls 
# in Merge Sort for the given application context.