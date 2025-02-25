import pandas as pd
import matplotlib.pyplot as plt


worst_case_data = pd.read_csv("q.csv")  
avg_case_data = pd.read_csv("q_avg.csv")  


plt.figure(figsize=(10, 6))
plt.plot(worst_case_data["Input_Size"], worst_case_data["Time_Taken"], 
         marker=".", linestyle=" ", color="b", label="Quick Sort Worst Case (O(N²))")
plt.plot(avg_case_data["Input_Size"], avg_case_data["Time_Taken"], 
         marker=".", linestyle=" ", color="r", label="Quick Sort Average Case (O(N log N))")


plt.xlabel("Input Size (N)")
plt.ylabel("Time Taken (nanoseconds)")
plt.title("Quick Sort Time Complexity: Worst-Case vs. Average-Case")
plt.legend()
plt.grid(True)


plt.show()
