Day 1 ---------------->>>>

problem : Magic Square --

This C++ program generates an odd-order Magic Square using the Siamese Method. It starts from the middle of the first row, placing numbers sequentially while moving up-left. If the position is occupied, it moves down instead. The process repeats until the n × n grid is filled. The sum of each row, column, and diagonal remains constant.

Problem : Pick with LinearSearch :--

This C++ program finds a peak element in an array. A peak is an element greater than its neighbors.
If the array has one element, it is the peak.
The first or last element is a peak if it's greater than its only neighbor.
Any element greater than both adjacent elements is also a peak.
The program prints the first peak found or "Peak does not exist".

 Problem : pick with BinarySearch :--

This C++ program finds a peak element in an array using Binary Search.
A peak is an element greater than or equal to its neighbors.
If the array has only one element, it is the peak.
The first or last element is a peak if it's greater than its only neighbor.
Any middle element greater than both adjacent elements is also a peak.
The program recursively searches in the direction where a peak is more likely to exist.
The program prints the index of a peak element in logarithmic time O(log n).

Problem :  Pick in 2D ----

This C++ program finds a peak element in a 2D matrix, where a peak is an element that is greater than its left, right, upper, and lower neighbors.
Approach:
Binary search on columns:
  Pick the middle column.
  Find the maximum element in this column.
Check if it's a peak:
  If it is greater than its left, right, upper, and lower neighbors, it's a peak.
  Otherwise, move the search left or right where a larger element exists.
This ensures an O(n log m) time complexity.
Output:
  The program prints the coordinates (row, column) of a peak element, or "No peak found".

 
 Problem : Power Calculation ---
 
This program calculates a^b using Exponentiation by Squaring, reducing time complexity to O(log b).
Approach:
If b == 0, return 1 (base case).
Recursively compute power(a, b/2).
If b is even: result = half * half.
If b is odd: result = a * half * half.



Day2 ---------------------------------------->>>>


Problem : Cosine Similarity : ------

This program calculates the cosine similarity between two text files based on word frequency vectors.

How It Works:
Reads two text files (vector1.txt and vector2.txt).
Processes text:
Converts words to lowercase.
Removes punctuation.
Filters out common words (e.g., "is", "the", "and").
Creates word frequency vectors for both files.
Computes cosine similarity to measure text similarity.

formula used :

cosine similarity = A.B  / ||A|| * ||B||   
A and B are word frequency vectors 

Problem : Heap short -----------

This program implements Heap Sort and measures its execution time for different input sizes, storing results in heap_sort_complexity.csv.

Heap Sort Functions:

  Heapify: Maintains max-heap.
  Build Heap: Converts array into a heap.
  Heap Sort: Sorts the array using heap properties.

Performance Analysis:
  Sorts arrays of increasing sizes (up to 100,000).
  Measures execution time using chrono.
  Saves results in CSV for graph plotting.

Output: CSV file with Input_Size, Time_Taken.


Problem : Insertion ------------

This program analyzes the time complexity of Insertion Sort under different cases:
Worst Case: Reverse sorted array (O(n²))
Average Case: Random array (O(n²))
Best Case: Already sorted array (O(n))

Implementation Details:
Generates arrays of increasing sizes (up to 1 billion).
Sorts them using Insertion Sort and measures execution time.
Prints results (size vs. time taken).


Problem : Merge sort  --------

Overview :
   Merge Sort is a divide-and-conquer sorting algorithm that recursively splits an array into 
   halves, sorts them, and merges them back.

Algorithm Steps :
   Divide the array into two halves.
   Recursively sort each half.
   Merge the sorted halves.
   
Time Complexity :
   Best Case: O(n log n)
   Average Case: O(n log n)
   Worst Case: O(n log n)

Space Complexity : 
   O(n) (due to auxiliary space for merging)


Problem : quick sort complexity ----------

Overview :
   Quick Sort is a divide-and-conquer sorting algorithm that selects a pivot, partitions the 
   array around it, and recursively sorts the subarrays.

Algorithm Steps
  Select a pivot element.
  Partition the array so that elements smaller than the pivot are on the left and larger ones 
  on the right.
  Recursively apply Quick Sort on the left and right subarrays.

Time Complexity
   Best Case: O(n log n)
   Average Case: O(n log n)
   Worst Case: O(n²) (when the smallest or largest element is always chosen as pivot)
Space Complexity
   O(log n) (due to recursion stack)


Day 3 ---------------------------------------------------------->>>>>>>>>>>>>>

Problem : fractional knapsack -----

Solves the Fractional Knapsack Problem using a Greedy Algorithm by sorting items based on profit, weight, and profit-to-weight ratio.

Steps:
   Generate random profit & weight.
   Compute profit-to-weight ratio.
   Sort & select items greedily.
   Calculate total profit.

Complexity
   Sorting: O(n²)
   Selection: O(n)
   Total: O(n²)

Day 4 ----------------------------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Problem : Matrix multiplication -----

Overview
    Recursive n × n matrix multiplication using divide and conquer (for power-of-2 sizes).

Complexity
    Standard Multiplication: O(n³)
    Recursive Approach: O(n³)

Usage
    Input matrix size (power of 2).
    Enter elements of matrices A & B.

Problem : strassen's method ------

Overview
    This program implements Strassen’s Algorithm for fast n × n matrix multiplication, reducing 
    time complexity compared to the standard approach.

Key Features
    Works for power-of-2 matrix sizes (e.g., 2, 4, 8, 16, …).
    Uses divide and conquer with 7 recursive multiplications instead of 8.

Complexity
   Standard method: O(n³)
   Strassen’s method: O(n².81) (Faster for large matrices)

Problem : Convex Hull Problem -----

Overview
   This program finds the convex hull of a set of 2D points using the QuickHull algorithm, a divide & conquer approach.

Steps
  Find Extreme Points (leftmost & rightmost).
  Partition Points into two sets.
  Recursively Find Hull using the farthest points.

Usage
 Input: Number of points n and n (x, y) coordinates.
 Output: Convex hull points.
🔹 Efficient (O(n log n)) 🔹 Works well for large datasets

Problem : Dijkastra algorithm ----

This program finds the shortest path from a given source vertex to all other vertices using Dijkstra's Algorithm with an adjacency matrix.

Input:
  Number of vertices (n).
  Randomly generated edge weights (INF for unreachable edges).
  Source vertex (v).
Output:
  Adjacency matrix.
  Shortest distances from the source to all vertices.

** Optimizable with priority queues for better efficiency.

Problem : Min Max using divide and conqure  -------------
  Finds the minimum and maximum in an array using Divide and Conquer.
Steps
 Split array recursively.
 Find min/max in each half.
 Merge results.

Time Complexity
 O(n) (Efficient). 


Day 5 ------------------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>

Problem : kruskal algorithm -----
   Implements Kruskal’s Algorithm using Min Heap to find the Minimum Spanning Tree (MST) of a graph.
Steps
  Min-Heapify edges based on weight.
  Extract minimum edge, check cycle using Union-Find.
  Add edge to MST if no cycle.
  Repeat until (n-1) edges are added.
Time Complexity
O(E log E) (Efficient). 



  
   






