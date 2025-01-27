import matplotlib.pyplot as plt
import numpy as np

raw_avg_10 = np.loadtxt("./Data/avg_case_10.txt")
raw_avg_30 = np.loadtxt("./Data/avg_case_30.txt")
raw_avg_50 = np.loadtxt("./Data/avg_case_50.txt")
raw_avg_90 = np.loadtxt("./Data/avg_case_90.txt")

raw_bes_case_10 = np.loadtxt("./Data/best_case_10.txt")
raw_bes_case_30 = np.loadtxt("./Data/best_case_30.txt")
raw_bes_case_50 = np.loadtxt("./Data/best_case_50.txt")
raw_bes_case_90 = np.loadtxt("./Data/best_case_90.txt")

raw_worst_case_10 = np.loadtxt("./Data/worst_case_10.txt")
raw_worst_case_30 = np.loadtxt("./Data/worst_case_30.txt")
raw_worst_case_50 = np.loadtxt("./Data/worst_case_50.txt")
raw_worst_case_90 = np.loadtxt("./Data/worst_case_90.txt")

# Array of the elements
x = [i for i in range(0, 10000, 10)]

# Now plot all of them together so all the best together
# all the worst together and so on
avg_10_x = raw_avg_10[:, 0]
avg_10_y = raw_avg_10[:, 1]
avg_30_x = raw_avg_30[:, 0]
avg_30_y = raw_avg_30[:, 1]
avg_50_x = raw_avg_50[:, 0]
avg_50_y = raw_avg_50[:, 1]
avg_90_x = raw_avg_90[:, 0]
avg_90_y = raw_avg_90[:, 1]

plt.subplot(2, 2, 1)
plt.plot(avg_10_x, avg_10_y, marker='o', color='red', label='k = 10')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 2)
plt.plot(avg_30_x, avg_30_y, marker='o', color='blue', label='k = 30')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 3)
plt.plot(avg_50_x, avg_50_y, marker='o', color='green', label='k = 50')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 4)
plt.plot(avg_90_x, avg_90_y, marker='o', color='orange', label='k = 90')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplots_adjust(wspace=0.4, hspace=0.4)

plt.suptitle("Average Case Comparison of K")  

plt.savefig("avg_case.png")

# Best case
bes_10_x = raw_bes_case_10[:, 0]
bes_10_y = raw_bes_case_10[:, 1]
bes_30_x = raw_bes_case_30[:, 0]
bes_30_y = raw_bes_case_30[:, 1]
bes_50_x = raw_bes_case_50[:, 0]
bes_50_y = raw_bes_case_50[:, 1]
bes_90_x = raw_bes_case_90[:, 0]
bes_90_y = raw_bes_case_90[:, 1]

plt.figure()

plt.subplot(2, 2, 1)
plt.plot(bes_10_x, bes_10_y, marker='o', color='red', label='k = 10')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 2)
plt.plot(bes_30_x, bes_30_y, marker='o', color='blue', label='k = 30')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 3)
plt.plot(bes_50_x, bes_50_y, marker='o', color='green', label='k = 50')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 4)
plt.plot(bes_90_x, bes_90_y, marker='o', color='orange', label='k = 90')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplots_adjust(wspace=0.4, hspace=0.4)

plt.suptitle("Best Case Comparison of K")  

plt.savefig("best_case.png")


worst_10_x = raw_worst_case_10[:, 0] 
worst_10_y = raw_worst_case_10[:, 1]
worst_30_x = raw_worst_case_30[:, 0] 
worst_30_y = raw_worst_case_30[:, 1]
worst_50_x = raw_worst_case_50[:, 0] 
worst_50_y = raw_worst_case_50[:, 1] 
worst_90_x = raw_worst_case_90[:, 0] 
worst_90_y = raw_worst_case_90[:, 1]

plt.figure()

plt.subplot(2, 2, 1) 
plt.plot(worst_10_x, worst_10_y, marker='o', color='red', label='k = 10') 
plt.legend() 
plt.xlabel('# of elements') 
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 2)
plt.plot(worst_30_x, worst_30_y, marker='o', color='blue', label='k = 30') 
plt.legend()
plt.xlabel('# of elements') 
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 3)
plt.plot(worst_50_x, worst_50_y, marker='o', color='green', label='k = 50') 
plt.legend() 
plt.xlabel('# of elements') 
plt.ylabel('time taken (μs)')

plt.subplot(2, 2, 4)
plt.plot(worst_90_x, worst_90_y, marker='o', color='orange', label='k = 90')
plt.legend()
plt.xlabel('# of elements')
plt.ylabel('time taken (μs)')

plt.subplots_adjust(wspace=0.4, hspace=0.4)

plt.suptitle("Worst Case Comparison of K")

plt.savefig("worst_case.png")