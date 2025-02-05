import matplotlib.pyplot as plt
import numpy as np  

# Generate x values for O(n²) within a reasonable range
x1 = np.linspace(100, 20000, 300)  # Keeping x1 values closer to x2 range
y1 = x1 ** 2  

# Given custom data points
x2 = np.array([5,25,125, 625, 3125,15625])  
y2 = np.array([1415000, 0, 1195000,8008000,331717000,12933604000])  

# Scale y2 to match y1's range
y2_scaled = y2 / max(y2) * max(y1)

# Create the plot
plt.figure(figsize=(10, 6))

# Plot O(n²) curve
plt.plot(x1, y1, linestyle='dashed', color='b', label="O(n²) Growth")  

# Plot custom data points
plt.plot(x2, y2_scaled, marker='o', linestyle='-', color='r', label="Custom Data (Scaled)")  

# Labels, title, and legend
plt.xlabel("X Values")
plt.ylabel("Y Values (Scaled)")
plt.title("Comparison: O(n²) vs. Custom Data (Scaled)")
plt.legend()
plt.grid(True, linestyle="--", linewidth=0.5)

# Show plot
plt.show()