# ploting the graph using the csv file of the data 

import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv("heap_sort_complexity.csv")


plt.plot(data["Input_Size"], data["Time_Taken"], marker=".", linestyle="", color="r", label="Heap Sort")


plt.xlabel("Input Size (N)")
plt.ylabel("Time Taken (seconds)")
plt.title("Heap Sort Time Complexity")
plt.legend()
plt.grid()


plt.show()
