import time
import random
import matplotlib.pyplot as plt

# for plotting graphs

# Function to perform Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min = i
        for j in range(i+1, n):
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]

# Function to generate Case A sequence (increasing order)
def generate_case_A_sequence(n):
    return list(range(n))

# Function to generate Case B sequence (decreasing order)
def generate_case_B_sequence(n):
    return list(range(n, 0, -1))

# Function to measure computation time for sorting
def measure_time(sort_func, arr):
    start_time = time.time()
    sort_func(arr)
    end_time = time.time()
    return end_time - start_time

# Generate input sequences and measure computation time
sequence_lengths = [100, 200, 300, 400, 500]  # Example sequence lengths
average_times = []
case_A_times = []
case_B_times = []

for length in sequence_lengths:
    random_seq = [random.randint(1, 1000) for _ in range(length)]
    case_A_seq = generate_case_A_sequence(length)
    case_B_seq = generate_case_B_sequence(length)
    
    # Measure computation time for each sequence type
    average_time = sum(measure_time(selection_sort, random_seq) for _ in range(10)) / 10
    case_A_time = sum(measure_time(selection_sort, case_A_seq) for _ in range(10)) / 10
    case_B_time = sum(measure_time(selection_sort, case_B_seq) for _ in range(10)) / 10
    
    average_times.append(average_time)
    case_A_times.append(case_A_time)
    case_B_times.append(case_B_time)

# Plot the results
plt.plot(sequence_lengths, average_times, label='Average Case')
plt.plot(sequence_lengths, case_A_times, label='Case A')
plt.plot(sequence_lengths, case_B_times, label='Case B')
plt.xlabel('Sequence Length')
plt.ylabel('Computation Time (seconds)')
plt.title('Computation Time of Selection Sort')
plt.legend()
plt.show()
