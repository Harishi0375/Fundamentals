import algorithms
import numpy as np
import random
import time
import csv
import sys 


def main():
    big_data = np.array([[random.randint(0, 10000) for _ in range(1001)] for _ in range(100000)])
    big_data_copy1 = np.copy(big_data)
    big_data_copy2 = np.copy(big_data)

    # with open("Lomuto.csv", "w") as f:
    #     writer  = csv.writer(f)
    #     for i in big_data:
    #         start = time.time()
    #         algorithms.quicksortL(i, 0, 1000)
    #         time_taken = time.time() - start
    #         writer.writerow([f"{time_taken}"])
    
    # with open("Hoar.csv", "w") as f:
    #     writer  = csv.writer(f)
    #     for i in big_data:
    #         start = time.time()
    #         algorithms.quicksortH(i, 0, 999)
    #         time_taken = time.time() - start
    #         writer.writerow([f"{time_taken}"])

    with open("Median.csv", "w") as f:
        sys.setrecursionlimit(10**10)
        writer  = csv.writer(f)
        for i in big_data:
            start = time.time()
            algorithms.quicksortM(i, 0, 999)
            time_taken = time.time() - start
            writer.writerow([f"{time_taken}"])


main()