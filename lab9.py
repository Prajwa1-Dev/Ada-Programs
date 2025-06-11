import matplotlib.pyplot as plt

# data collected
n_values = [6000, 15450, 24484, 1100, 19439]
time_taken = [0.001, 15450, 19439, 24484, 30111]  # replace with actual times recorded

plt.plot(n_values, time_taken, marker='o')
plt.title('Selection Sort Time Complexity')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time taken (seconds)')
plt.grid(True)
plt.show()