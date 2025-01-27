from algorithms import bucket_sort, counting_sort, radix_sort_string, radix_sort
import random

first_arr = [9,1,6,7,6,2,1]
second_arr = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
strings = ["word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"]
radix_arr = [random.randint(0, 100) for _ in range(1000)]


# 1 a and b
print(f"first array sorted {counting_sort(first_arr)}")
print(f"second sorted array {bucket_sort(second_arr)}")

radix_sort_string(strings)
radix_sort(radix_arr)

print(f"sorted strings {strings}")
print(f"sorted array for radix sort {radix_arr}")