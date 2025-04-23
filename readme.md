# ADA lab Works :

                                          # Day 1
##**1.Magic Square**

**Objective** :  To generate odd order magic square 
This C++ program generates an odd-order Magic Square using the Siamese Method. It starts from the middle of the first row, placing numbers sequentially while moving up-left. If the position is occupied, it moves down instead. The process repeats until the n × n grid is filled. The sum of each row, column, and diagonal remains constant. 

**Time Complexity Analysis**
•	The program fills the n×n times n×n matrix exactly once.
•	Each number from 1 to n2n is placed in one iteration.
•	Checking and updating positions is O(1) for each step.
Thus, the overall time complexity is:
O(n^2) 
where n is the size of the square.
For the time complexity graph on the different input :


![Screenshot 2025-03-26 151539](https://github.com/user-attachments/assets/90fccd34-9520-4ee3-8214-b319855774d5)


##**2. 1D Peak**

**Objective** : This C++ program finds a peak element in an array using a binary search-based approach.
This C++ program finds a peak element in an array using Binary Search.
A peak is an element greater than or equal to its neighbors.
•	If the array has only one element, it is the peak.
•	The first or last element is a peak if it's greater than its only neighbor.
•	Any middle element greater than both adjacent elements is also a peak.
•	The program recursively searches in the direction where a peak is more likely to exist.
The program prints the index of a peak element in logarithmic time O(log n).


![WhatsApp Image 2025-04-02 at 10 14 28_98055800](https://github.com/user-attachments/assets/e628891f-342e-434c-9735-1a024a7b6ddd)





## 3. **2D Peak**

**Objective** : finding the 2D peak from an 2D array/Matrix
This C++ program finds a peak element in a 2D matrix, where a peak is an element that is greater than its left, right, upper, and lower neighbors.

**Approach:**
1.	Binary search on columns:
o	Pick the middle column.
o	Find the maximum element in this column.

3.	Check if it's a peak:
o	If it is greater than its left, right, upper, and lower neighbors, it's a peak.
o	Otherwise, move the search left or right where a larger element exists.
4.	This ensures an O(n log m) time complexity.

**Output**:The program prints the coordinates (row, column) of a peak element, or "No peak found".

![WhatsApp Image 2025-04-02 at 10 14 28_10beabac](https://github.com/user-attachments/assets/92fc5b10-9b2c-4c02-a388-ce46d586cb73)





## **Power Calculation using logn **

**Objective**: To find the a to the power b without the n^2 complexity

Power of a Number (Recursive Approach)
This C++ program calculates a^b (a raised to the power of b) using recursion.

**Approach:**
•	Base Case: If b == 0, return 1.
•	Recursive Case:
o	If b is even, compute power(a, b/2) once and square it.
o	If b is odd, multiply a with power(a, b/2) * power(a, b/2).

**Time Complexity:** 
•	This implementation is inefficient (O(2^log b)) because it computes power(a, b/2) twice.
•	It can be optimized using exponentiation by squaring to O(log b).

![WhatsApp Image 2025-04-02 at 10 27 25_b1acf11a](https://github.com/user-attachments/assets/883eb291-39a4-480b-9b0d-335e4c67ee25)





                                            # Day2

**1. Cosine similarity**

** Objective :**   To find the similarity between the the different files
This program calculates the cosine similarity between two text files based on word frequency vectors.
**How It Works:**
1.	Reads two text files (vector1.txt and vector2.txt).
2.	Processes text:
o	Converts words to lowercase.
o	Removes punctuation.
o	Filters out common words (e.g., "is", "the", "and").
3.	Creates word frequency vectors for both files.
4.	Computes cosine similarity to measure text similarity.

![image](https://github.com/user-attachments/assets/2e8434f0-b9cd-4b6f-a8e6-6c1c3bff78bf)


![Screenshot 2025-04-02 141218](https://github.com/user-attachments/assets/63026d1d-be70-4a76-a8af-0028c2d544e3)




** 2. Heap sort **

**Objective :** Understanding the heap sort and finding its time complexity
Heap Sort Complexity Analysis
This program analyzes the time complexity of Heap Sort by sorting arrays of different sizes and recording the execution time in a CSV file.

**How It Works:**
1.	Heap Sort Implementation:
o	Heapify: Maintains the max-heap property.
o	Build Heap: Converts an array into a max heap.
o	Heap Sort: Extracts elements one by one and maintains the heap.

**2.	Performance Analysis:**
o	Runs Heap Sort on arrays of increasing sizes (up to 100,000).
o	Uses chrono to measure execution time.
o	Stores results in a CSV file (heap_sort_complexity.csv).

![image](https://github.com/user-attachments/assets/fe6cd516-d385-43c9-8404-a02eee695fb8)



**3. Insertion Sort ** 

This program analyzes the time complexity of Insertion Sort under different cases:
Worst Case: Reverse sorted array (O(n²))
Average Case: Random array (O(n²))
Best Case: Already sorted array (O(n))

Implementation Details:
Generates arrays of increasing sizes (up to 1 billion).
Sorts them using Insertion Sort and measures execution time.
Prints results (size vs. time taken).

![image](https://github.com/user-attachments/assets/b7a00ea0-e09c-47f2-b439-a131fe5cc054)



**4. Merge Sort **

**Overview :**
   Merge Sort is a divide-and-conquer sorting algorithm that recursively splits an array into 
   halves, sorts them, and merges them back.

**Algorithm Steps :**
   Divide the array into two halves.
   Recursively sort each half.
   Merge the sorted halves.
   
**Time Complexity :**
   Best Case: O(n log n)
   Average Case: O(n log n)
   Worst Case: O(n log n)

**Space Complexity :** 
   O(n) (due to auxiliary space for merging)

   ![image](https://github.com/user-attachments/assets/52002dc7-d9c0-42ac-9667-df68274d0772)

                                             # Day 3

**1. Quick sort time complexity **

**Overview :**
   Quick Sort is a divide-and-conquer sorting algorithm that selects a pivot, partitions the 
   array around it, and recursively sorts the subarrays.

**Algorithm Steps**
  Select a pivot element.
  Partition the array so that elements smaller than the pivot are on the left and larger ones 
  on the right.
  Recursively apply Quick Sort on the left and right subarrays.

**Time Complexity**
   Best Case: O(n log n)
   Average Case: O(n log n)
   Worst Case: O(n²) (when the smallest or largest element is always chosen as pivot)
   
**Space Complexity**
   O(log n) (due to recursion stack)

![image](https://github.com/user-attachments/assets/6f686b1c-4772-4beb-a1b0-d94cd03fcb70)


**2. fractional Knapsack ** 

Solves the Fractional Knapsack Problem using a Greedy Algorithm by sorting items based on profit, weight, and profit-to-weight ratio.

**Steps:**
   Generate random profit & weight.
   Compute profit-to-weight ratio.
   Sort & select items greedily.
   Calculate total profit.

**Complexity**
   Sorting: O(n²)
   Selection: O(n)
   Total: O(n²)

                                                 # Day 4 & 5 
                                                 
**1. Matrix multiplication **

**Overview**
    Recursive n × n matrix multiplication using divide and conquer (for power-of-2 sizes).

**Complexity**
    Standard Multiplication: O(n³)
    Recursive Approach: O(n³)

**Usage**
    Input matrix size (power of 2).
    Enter elements of matrices A & B.

    
![Screenshot 2025-04-02 150500](https://github.com/user-attachments/assets/f039ec43-03ae-49f8-8a4c-2c743b2000e6)

    

**2. strasseson method **

**Overview**
    This program implements Strassen’s Algorithm for fast n × n matrix multiplication, reducing 
    time complexity compared to the standard approach.

**Key Features**
    Works for power-of-2 matrix sizes (e.g., 2, 4, 8, 16, …).
    Uses divide and conquer with 7 recursive multiplications instead of 8.

**Complexity**
   Standard method: O(n³)
   Strassen’s method: O(n².81) (Faster for large matrices)

   ![Screenshot 2025-04-02 152044](https://github.com/user-attachments/assets/56c6db5c-ddf9-4553-ac8c-7ce1d90303f3)



**3. convex hull problem :**

**Overview**
This program implements the QuickHull Algorithm to find the convex hull of a set of 2D points. The convex hull is the smallest convex boundary that encloses all given points.

**Key Features**
•	Efficient Divide & Conquer approach
•	Faster than Graham’s scan & Jarvis March for large inputs
•	Works in O(n log n) average case complexity

**How It Works**
1.	Find Extremes: Identifies leftmost and rightmost points.
2.	Partition Points: Splits points into two sets (above & below the line).
3.	Recursive Hull Formation: Finds farthest points and recursively constructs the hull.
**🔹 Efficient (O(n log n))**

2D visualisation :
![image](https://github.com/user-attachments/assets/9f922f5f-de6c-4a25-be91-914262e7632b)

time complexity graph :

![image](https://github.com/user-attachments/assets/bf309662-8536-4be9-9fe0-40c66b12a30f)



 
**4. Iterative Quick sort :**
   
 This program implements QuickSort using an iterative approach instead of recursion. It sorts an array of integers entered by the user. The program uses a stack to replace the recursive function calls, making it more memory-efficient compared to the traditional recursive QuickSort.
 
**How It Works**
1.	The user enters the size of the array and its elements.
2.	The Iterative QuickSort algorithm is applied to sort the array.
3.	The sorted array is displayed as output.

**Algorithm**
1.	Partitioning:
o	Select the first element as the pivot.
o	Rearrange elements so that smaller elements are on the left and larger ones on the right.
o	Place the pivot in its correct position.
2.	Iterative QuickSort using a Stack:
o	Push the low and high indices onto the stack instead of using recursion.
o	Keep processing subarrays until the stack is empty.

**Time Complexity**
•	Best/Average Case (O(n log n)) – When the pivot divides the array into nearly equal halves.
•	Worst Case (O(n²)) – If the pivot is always the smallest or largest element (unbalanced partitioning).

                          **graph is same like a recursive quick sort **
  	

**5. Finding the min and maximum using devide and conquer :**

**Overview:**
This program finds the minimum and maximum values in an array using the divide and conquer approach. Instead of a simple linear scan, it recursively divides the array into smaller parts, finds the min-max in each part, and then merges the results efficiently.

**Algorithm Explanation**
1.	Recursive Division:
o	If the array has one element, it is both min and max.
o	Otherwise, the array is divided into two halves.
o	The min-max of each half is computed recursively.
2.	Merging Results:
o	The min-max of both halves are compared, and the final min-max is determined.

**Time Complexity Analysis**
Let T(n) be the time complexity of the algorithm:
•	Divide Step: The array is split into two halves → O(1).
•	Recursive Calls: Two recursive calls for two halves → T(n) = 2T(n/2) + O(1).
•	Merging Step: Takes O(1) constant time.

**Solving the recurrence using the Master Theorem, we get:**
•	Best & Average Case Complexity: O(n)
•	Worst Case Complexity: O(n)



  ![Screenshot 2025-04-02 154231](https://github.com/user-attachments/assets/45ceb117-a9c0-4c91-8a13-ce4e674eb994)


**   6. Checking the point is in the triagle or not :**

**Overview : ** This program determines whether a given point (x, y) lies inside a triangle defined by three vertices (x1, y1), (x2, y2), (x3, y3) using the cross-product method.

**Algorithm Explanation**

**1.	Cross Product Calculation:**

o	The cross product of two vectors determines the relative orientation of a point to a line.
o	The sign of the cross product tells whether a point lies to the left or right of a directed line segment.
**2.	Conditions for a Point Inside the Triangle:**

o	If the point (x, y) lies inside the triangle, it must be on the same side of all three triangle edges.
o	This means all three cross products have the same sign (either all positive or all negative).

**Time Complexity Analysis**
The algorithm performs a constant number of calculations (three cross-product evaluations and three comparisons), making it:
•	Time Complexity: O(1) (Constant Time)
•	Space Complexity: O(1) (No Extra Space Used)



**7. Activity Selection problem **

The Activity Selection Problem is a greedy algorithm problem where we aim to select the maximum number of non-overlapping activities that can be performed by activity selection problem 

**Overview**
This C++ program implements an activity selection problem where multiple activities have a start time, end time, and profit. The goal is to select the maximum number of non-overlapping activities using different sorting strategies.

**How It Works**
1.	The user enters the number of activities (n).
2.	For each activity, the user provides:
o	Start Time
o	End Time
o	Profit
3.	The program sorts and selects activities using the three sorting strategies.
4.	It prints the selected activities and the maximum number of non-overlapping activities for each approach.

**Complexity Analysis**

•	Sorting: O(n log n) (using std::sort()).
•	Activity selection: O(n) (iterating through activities).
•	Overall complexity: O(n log n) + O(n) = O(n log n). 


**8. Median of an array **

**Overview**
This C++ program finds the median of an unsorted array using the QuickSelect algorithm, an efficient selection algorithm similar to QuickSort. It avoids full sorting and finds the median in O(n) average time complexity.

**How It Works**

**1.	QuickSelect Algorithm**
o	Selects the k-th smallest element without sorting the entire array.
o	Uses a partitioning technique similar to QuickSort.

**2.	Finding the Median**
o	If the array has an odd number of elements, the median is the middle element.
o	If the array has an even number of elements, the median is the average of the two middle elements.
o	QuickSelect is used to find both elements efficiently.

**Time Complexity Analysis**
•	Best/Average Case: O(n) (Linear time, as we only partition necessary parts of the array).
•	Worst Case: O(n²) (Occurs when always picking the worst pivot, but can be improved with random pivot selection). 



![Screenshot 2025-04-02 155311](https://github.com/user-attachments/assets/730d5a13-ea93-429e-9a69-32bcaf906767)



**9. Dikastra's algorithm **

**Overview**
This C++ program implements Dijkstra’s Algorithm to find the shortest path from a single source vertex to all other vertices in a graph. It uses a randomly generated weighted adjacency matrix to represent the graph.

**How It Works**

1.	Graph Representation:
   
o	The graph is represented using a cost adjacency matrix (cost[i][j] stores the weight of the edge between vertex i and j).
o	Edge weights are randomly assigned (values between 1 and 10, with higher values set as INF for disconnected edges).

2.	Dijkstra’s Algorithm:
o	A distance array (dist[]) stores the shortest known distance from the source vertex.
o	A flag array (flag[]) keeps track of visited nodes.
o	At each step, the node with the minimum distance is selected, and its neighboring distances are updated.

**Time Complexity Analysis**
•	Best/Average Case: O(n²) (Using an adjacency matrix without a priority queue).
•	Optimized version with a min-heap (not implemented here) would be O((n + e) log n).


![Screenshot 2025-04-02 162216](https://github.com/user-attachments/assets/c54d896e-cef6-4ec0-8e20-09333fa4691b)



                                                # Day 6 

**1 . Kruskal algorithm ** 

**Overview**
This C++ program implements Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a given graph. It uses a min-heap (priority queue) for efficient edge selection and a union-find data structure to detect cycles while adding edges to the MST.

**How It Works**
1.	Graph Representation:
o	The graph is represented as an edge list, where each edge consists of:
	a: Start vertex
	b: End vertex
	c: Weight (cost) of the edge
o	The edges are stored in a vector and arranged in a min-heap for efficient selection of the smallest edge.
2.	Kruskal’s Algorithm:
o	Uses a Min-Heap to sort edges by increasing weight.
o	Uses Union-Find (Disjoint Set) to check for cycles before adding an edge to the MST.
o	Continues until we have n-1 edges in the MST or the edges are exhausted.

**Time Complexity Analysis**
•	Heap Construction: O(E log E) (Sorting edges using min-heap).
•	Find & Union Operations: O(E log V) (Using Union-Find with path compression).
•	Overall Complexity: O(E log E) (Efficient for sparse graphs).


![Screenshot 2025-04-17 160816](https://github.com/user-attachments/assets/9b981c92-a6b7-4193-825e-e48792a890a5)



**2. Prim's algorithm **

**Overview**

Prim’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. The MST connects all vertices with the minimum possible total edge weight without forming cycles.

**How the Algorithm Works**
1.	Start with any vertex.
2.	Select the smallest edge connecting a visited vertex to an unvisited one.
3.	Mark the selected vertex as visited.
4.	Repeat until all vertices are included in the MST.

**Time Complexity**
•	Using adjacency matrix: O(n²)
•	Using priority queue (binary heap): O(E log V)

![Screenshot 2025-04-17 160953](https://github.com/user-attachments/assets/f8802bc2-a828-4aa3-98d0-88329e1e6bad)



                                                       # day 7




**1 . Multistage Graph (Minimum cost path)**

**Overview:** This program finds the minimum cost path from source (1) to destination (n) in a multistage directed acyclic graph (DAG) using bottom-up dynamic programming.

**How It Works**

•	The graph is stored using:

o	adj[]: adjacency list

o	cost[][]: cost matrix

•	fdist[i]: stores min cost from node i to destination.

•	d[i]: helps reconstruct the path by storing the next node from i.

**Time Complexity**

•	O(V + E)

o	For each node, we check all its outgoing edges once in reverse topological order.

o	Works efficiently as the graph is acyclic and layered.


![image](https://github.com/user-attachments/assets/b95d062f-d05d-4ce4-a08c-e6e874825303) 


### ** fibonacci with dynamic programming **

time complexity : which is reduced to o(n) from o(2^n) using dp 

![image](https://github.com/user-attachments/assets/2392202b-96e2-4e5a-b0f3-c66371680717)



**2.  All pair shortest path :**
**Overview : ** This program finds the shortest paths between all pairs of vertices in a directed graph using the Floyd-Warshall algorithm

**Features:**

•	Works for graphs with positive and negative edge weights
•	Detects negative weight cycles
•	Prints the shortest path distances between all pairs of nodes
•	Simple and easy to understand

**•	Time Complexity:**

O(n³), where n is the number of vertices.
This is because it uses three nested loops: one for each vertex as an intermediate, start, and end node.

**•	Space Complexity:**

O(n²), for storing the distance matrix of all pairs.

![Screenshot 2025-04-17 002311](https://github.com/user-attachments/assets/237774a0-00a3-4305-901d-edf3abfa682e)

![Screenshot 2025-04-17 002259](https://github.com/user-attachments/assets/4c319abc-f517-4a65-9167-1dd4fabf4959)




                                        # day 8

**1 – Travelling Sales Person Problem :**

The Traveling Salesman Problem (TSP) is a classic optimization problem where:

•	Given a list of cities and distances between each pair
•	Find the shortest route that visits each city exactly once and returns to origin

**Key Challenges :**

1.	NP-Hard Complexity:
   
o	Naive brute-force approach has O(n!) complexity
o	Dynamic programming reduces to O(n²·2ⁿ) - still exponential

3.	Practical Limitations:

o	For n > 15, becomes computationally expensive
o	Memory usage grows exponentially with n

5.	Python-Specific Issues:
   
o	Recursion depth limits
o	Function call overhead in Python
o	Cache/memoization memory usage

**Solution Approach**

**This implementation uses:**

•	Memoization (via lru_cache)
•	Bitmask technique for visited cities
•	Dynamic Programming to avoid recomputation

**Benchmarking Insights**

1.	Theoretical vs Actual:
o	Expected: O(n²·2ⁿ) complexity
o	Observed: Closer to O(n·2ⁿ) due to Python overhead


![Screenshot 2025-04-17 144652](https://github.com/user-attachments/assets/d8e18ca1-9c22-422f-9b96-f55d1449d8ff)



**2 - 0/1 knapsack**

**Overview**

This C++ program implements a dynamic programming solution to the classic 0/1 Knapsack problem. The solution uses a merge-and-purge technique to efficiently explore the solution space while avoiding redundant computations.

**Features**

•	Dynamic Programming Solution: Implements the standard DP approach for 0/1 Knapsack
•	Merge-Purge Optimization: Reduces the state space by eliminating dominated (p,w) pairs
•	Solution Tracing: Reconstructs the optimal set of items after computing the maximum profit
•	Benchmarking: Includes timing functionality to measure performance

**Complexity Analysis**

•	Time Complexity: O(n×2ⁿ) in worst case, O(n×W) pseudo-polynomial when weights are bounded
•	Space Complexity: O(n×2ⁿ) for storing all solution sets


![Screenshot 2025-04-17 150951](https://github.com/user-attachments/assets/581f77ce-afb9-46f1-afc3-d3f8cf824f87)





**3 – Matrix chain multiplication **

**Overview :** Solves the matrix chain ordering problem using dynamic programming to minimize scalar multiplications.

**Features**

•	 Optimal parenthesization
•	 Complexity analysis (theoretical & empirical)
•	 Visualization of complexity
•	 C++ and Python implementations

**Complexity**

Metric	Complexity: 

Time **	O(n³)**
Space 	**O(n²)**

 

![Screenshot 2025-04-17 153408](https://github.com/user-attachments/assets/801ff878-9abb-4e55-b637-3107c23bde41)


                                               # Day 9

**1 – Longest common subsequence** 

**📝 Goal:**

Find the Longest Common Subsequence between two strings using Dynamic Programming.

**How It Works:**

•	Builds two tables:

o	c[i][j] → stores length of LCS for substrings X[0..i-1] and Y[0..j-1].
o	b[i][j] → stores the direction to trace the LCS.

•	Print_LCS() uses table b to print the LCS string.

** Example Input:**
                  X = "ABCBDAB"
                  Y = "BDCABA"
**Output :**
                  Length of LCS: 4
                  LCS: BCBA
**Complexity:**
•	Time: O(m × n)
•	Space: O(m × n)
Where m and n are the lengths of input strings X and Y.


 ![image](https://github.com/user-attachments/assets/dba7bc25-08f9-4da7-9ad9-0da810106251)


**2 -  N-queens or 4 queens problem :**

**Goal:**

Place N queens on an N x N chessboard such that no two queens attack each other — not in the same row, column, or diagonal.

**How It Works:**

•	x[k] stores the column position of the queen placed in row k.
•	Place(k, i) checks if a queen can be safely placed at row k, column i.
•	Uses backtracking to explore all valid queen placements.

**Complexity:**

•	Time Complexity: O(N!) in the worst case
•	Space Complexity: O(N) for storing positions (plus recursion stack)

**Time complexity graph :**


![image](https://github.com/user-attachments/assets/c23fbe74-3074-4800-a11e-d9a7ba2a2547)

  



