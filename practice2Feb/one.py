import numpy as np
import matplotlib.pyplot as plt

# Load data from file
sizes, times = np.loadtxt("complexity.txt", unpack=True)

# Compute theoretical complexities
O_n = sizes / np.max(sizes) * np.max(times)  # Scale O(n)
O_log_n = (np.log(sizes) / np.log(np.max(sizes))) * np.max(times)  # Scale O(log n)

# Plot the actual execution time
plt.figure(figsize=(10, 6))
plt.plot(sizes, times, marker="o", label="Actual Execution Time", color="blue")

# Plot theoretical complexities
plt.plot(sizes, O_n, linestyle="--", label="O(n) Complexity", color="red")
plt.plot(sizes, O_log_n, linestyle="--", label="O(log n) Complexity", color="green")

# Labels and Formatting
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (nanoseconds)")
plt.title("Time Complexity Analysis of 1D Peak Finding")
plt.xscale("log")  # Use log scale for better visualization
plt.yscale("log")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Show Plot
plt.show()
