import matplotlib.pyplot as plt
import numpy as np

'''
d) I continue e back in the cpp file so please check there
'''

# DataA
data = np.loadtxt('DataA.txt')
elements = data[:, 0]
time_taken = data[:, 1]
y = [i for i in range(8000)]

dataB = np.loadtxt('DataB.txt')

# Extract elements and time taken for DataB
elements_B = dataB[:, 0]
time_taken_B = dataB[:, 1]

plt.plot(elements_B, time_taken_B, marker='o', label='Worst Case')
plt.plot(elements, time_taken, marker='s', label='Best Case')
# plt.xlabel('Number of Elements')
# plt.ylabel('Time Taken (milliseconds)')

# compute the average time taken for DataA + dataB
average_time = (time_taken + time_taken_B) / 2

# plot the average time taken
#plt.plot(elements, average_time, marker='o', label='Average Time Taken')


plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (milliseconds)')
plt.title('Time Taken vs Number of Elements')
plt.grid(True)
plt.legend()
plt.title('Time Taken vs Number of Elements')

plt.show()