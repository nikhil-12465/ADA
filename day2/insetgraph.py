import matplotlib.pyplot as plt
import numpy as np  

# Generate x values for O(n²) within a reasonable range
x1 = np.linspace(100, 2000, 300)  # x1 range from 100 to 2000
y1 = x1 ** 2  # O(n²) growth

# Given custom data points
x2 = np.array([5, 25, 125, 625, 3125, 15625, 78125])  
y2 = np.array([0, 0, 0, 0, 12088000, 253739000, 6533091000])  

# Rescale x2 to match the range of x1
x2_rescaled = np.interp(x2, (x2.min(), x2.max()), (x1.min(), x1.max()))

# Rescale y2 to match the range of y1
y2_rescaled = np.interp(y2, (y2.min(), y2.max()), (y1.min(), y1.max()))

# Create the plot
plt.figure(figsize=(10, 6))

# Plot O(n²) curve
plt.plot(x1, y1, linestyle='dashed', color='b', label="O(n²) Growth")  

# Plot custom data points (rescaled)
plt.plot(x2_rescaled, y2_rescaled, marker='o', linestyle='-', color='r', label="Custom Data (Rescaled)")  

# Labels, title, and legend
plt.xlabel("X Values")
plt.ylabel("Y Values")
plt.title("Comparison: O(n²) vs. Custom Data")
plt.legend()
plt.grid(True, linestyle="--", linewidth=0.5)

# Show plot
plt.show()




# average case 
# import matplotlib.pyplot as plt
# x = [1000,10000,100000]
# y = [0,57320000,5240941000]

# plt.figure(figsize=(10, 6))
# plt.plot(x,y,label='TEST',color='m', marker='.', markersize=20, markeredgecolor='black', markerfacecolor='red')
# plt.xlabel('x-axis')
# plt.ylabel('y-axis')
# plt.title('Customizing Line Chart')
# plt.grid(True)
# plt.legend()
# plt.show()


# best case :-

# import matplotlib.pyplot as plt
# x = [1000,10000,100000]
# y = [0,0,3407000]

# plt.figure(figsize=(10, 6))
# plt.plot(x,y,label='TEST',color='m', marker='.', markersize=20, markeredgecolor='black', markerfacecolor='red')
# plt.xlabel('x-axis')
# plt.ylabel('y-axis')
# plt.title('Customizing Line Chart')
# plt.grid(True)
# plt.legend()
# plt.show()

# worst case :



