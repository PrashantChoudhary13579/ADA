## LAB 1

1. Find the peak element in 1 Dimension array.

- Calculate the middle index as mid = (low + high) / 2.
- Check if arr[mid] is a peak element (greater than or equal to both neighbors). If true, print and return.
- If the left neighbor is greater (arr[mid-1] > arr[mid]), recursively search in the left half (low to mid-1).
- Otherwise, search in the right half (mid+1 to high).
- Repeat the process until a peak element is found and return the value.

Time Complexity - O(log n)
Space Complexity - O(1)

2. Find the peak element in 2 Dimension array.

- Input: A matrix mat of size n × m.
- Perform binary search on columns (low = 0, high = m-1).
- For each column mid, find the row with the maximum value using max function.
- If mat[row][mid] is greater than both its neighbors (left and right), it's a peak, print coordinates.
- If the left neighbor is larger, update high = mid - 1 (search left).
- If the right neighbor is larger, update low = mid + 1 (search right).
- Repeat until a peak is found or print "no peak found."

Time Complexity - O(n * log m)
Space Complexity - O(1)

3. Magic Square for ODD matrix

- Initialize an n × n matrix with all elements as 0.
- Start at (0, n/2) and loop from 1 to n*n.
- Place i at arr[row][col] and compute next position.
- If next cell is occupied, move down, else move diagonally up-left.
- Repeat until the matrix is filled, then print the magic square.

Time Complexity - O(n^2)
Space Complexity - O(n^2)

4. Finding the square of a number in O(log n) T.C.

- Input: Two integers a (base) and b (exponent).
- Base Case: If b == 0, return 1.
- If b is even, compute power(a, b/2) and square the result.
- If b is odd, compute power(a, b/2), square it, and multiply by a.
- Recursively break down the exponent by halving it until b == 0.
- Output: Return the computed result for a^b.

Time complexity - O(log b)
Space complexity - O(log b)

## LAB 2

1. Bubble sort 

- Start with an unsorted array arr[] of size n.
- Iterate over the array with an outer loop, from i = 0 to n-1.
- In each iteration, use an inner loop to compare adjacent elements from j = 0 to n-i-2.
- If arr[j] > arr[j+1], swap the two elements.
- After each outer loop pass, the largest element is placed at the end.
- Repeat the process until no swaps are needed, indicating the array is sorted.

Time Complexity:
    Best Case - O(n) // When elements are arranged in sorted order

    Average Case - O(n^2) // when elements are arranged in random order

    Worst Case - O(n^2) // when elements are arranged in reverse order

Space Complexity - O(1)

2. Insertion Sort 

- Start from i = 1 to n-1, treating a[i] as the key.
- Store a[i] in temp, then set j = i - 1.
- While j >= 0 and a[j] > temp, shift a[j] to a[j + 1] and decrement j.
- Place temp at a[j + 1].
- Repeat until the array is sorted.

Time Complexity:
    Best Case - O(n) // When elements are arranged in sorted order

    Average Case - O(n^2) // when elements are arranged in random order

    Worst Case - O(n^2) // when elements are arranged in reverse order

Space Complexity - O(1)

3. Quick Sort

- Choose a pivot element (e.g., the last element in the array).
- Partition the array such that elements smaller than the pivot are on the left, and those larger are on the right.
- Place the pivot in its correct sorted position.
- Recursively apply the same steps to the sub-arrays to the left and right of the pivot.
- Repeat until the sub-arrays contain only one element or are empty (base case).

Time Complexity:
    Best Case - O(n log n) // When the pivot divides the array into two nearly equal sub array 

    Average Case - O(n log n) // When the pivot divides the array into reasonably balanced sub-array

    Worst Case - O(n^2) // When the pivot is always the smallest or largest element

Space Complexity - O(log n)

4. Merge Sort 

- Divide the array into two halves recursively until each sub-array has one element.
- Compare and merge the sub-arrays by placing the smaller element first.
- Continue merging until the entire array is sorted.
- Each division of the array is handled separately.
- Final result is a sorted array.

Time Complexity: 
// No matter the input, it will divide the array into sub-array and then merge

    Best Case - O(n log n) 

    Average Case - O(n log n) 

    Worst Case - O(n log n) 

Space Complexity - O(n)

5. Cosine Similarity 

- Read two text files, input1.txt and input2.txt.
- Convert words to lowercase, remove punctuation, and exclude common words.
- Create a set of unique words from both files.
- Create frequency vectors for both files based on the unique words.
- Compute the dot product of the two frequency vectors.
- Calculate the magnitudes of both vectors.
- Compute cosine similarity = (dot product)/(magnitude of vector 1 × magnitude of vector 2)
- Output the cosine similarity value.

Time Complexity - O(n + m)
Space Complexity - O(n + m)
    where n = total number of words in both files
          m = number of unique words 
          
## LAB 3

1. Fractional Knapsac Problem 

- Initialize N items with random profit and weight, then compute profitPerWeight. 
- Sort the items in three ways: by profit (descending), weight (ascending), and profit/weight ratio (descending). 
- In the knapsack function, traverse the sorted items, adding them fully if possible; otherwise, take a fractional part and stop when the knapsack is full. 
- Finally, print the total profit for each sorting method. 

Time Complexity - O(n log n)
Space Complexity - O(n)

## LAB 4

1. Finding the max and min element using the Divide and Conquor

- Input the array size and initialize a dynamic array with random values.
- Define max_min function using Divide and Conquer to find the maximum and minimum:
- If one element, update max & min.
- If two elements, compare and update max & min.
- Otherwise, divide the array into two halves, recursively find max & min, and update them.
- Call max_min on the entire array to compute the final maximum and minimum.
- Print the array, maximum, and minimum values.

Time Complexity - O(n)
Space Complexity - O(log n)

2. Program for matrix multiplication

- The algorithm begins by taking the matrix size ( n ) as input and dynamically allocating memory for matrices ( A, B, ) and ( C ). 
- Matrices ( A ) and ( B ) are initialized with random values, while ( C ) is initialized to zero.
- The function MatrixMul recursively divides the matrices into submatrices and computes their product using a divide-and-conquer approach. 
- The making_C_mat function helps in forming the resulting matrix (C) by selecting appropriate submatrices from  (A) and (B), and the multiplyingFirst function performs element-wise multiplication and sums up the values. 
- Finally, the matrices are printed before and after multiplication.

Time Complexity - O(n³)
Space Complexity - O(n²)

3. Find whether the point is in or out of the triangle

- Generate random coordinates for the three vertices of a triangle.
- Generate a random point (px, py) to check its position relative to the triangle.
- Compute the area of the triangle using the determinant method.
- Compute the areas of three smaller triangles formed by (px, py) and two of the triangle’s vertices.
- Compare the sum of the three smaller triangle areas with the original triangle’s area.
- If the sum matches the original area, the point is inside; otherwise, it is outside.
- Print the triangle vertices, calculated areas, and the result.

Time complexity - O(1)
space complexity - O(1)

4. Quickhull Program

- Generate n random points with x and y coordinates.
- Find the leftmost (min x) and rightmost (max x) points.
- Partition remaining points into two sets based on their position relative to the line formed by extreme points.
- Find the farthest point from this line using area calculations.
- Recursively apply QuickHull on subsets formed by this farthest point.
- Stop recursion when no more points lie outside the hull boundary.
- Collect and print the convex hull points.

Time Complexity: 

    Best Case - O(n logn) 

    Average Case - O(n logn) 

    Worst Case - O(n^2) 

Space Complexity - O(n)

## LAB 5 

1. Activity Selection 

- Store activities as pairs of (end time, start time) to facilitate sorting.
- Sort the activities based on their end times in ascending order.
- Initialize a variable finish to track the end time of the last selected activity.
- Iterate through the sorted activities and select an activity if its start time is greater than finish, updating finish accordingly.
- Count and return the number of selected activities.

Time Complexity - O(n log n)
Space Complexity - O(n)

2. Convex Hull

- Find the leftmost and rightmost points in the given set.
- Recursively find the farthest point from the line segment joining these two points.
- Divide the remaining points into two subsets, based on which side of the line they lie on.
- Recursively apply the same process to find more hull points.
- Stop when no more points are left to consider and add the boundary points to the convex hull.
- Print the points forming the convex hull.

Time Complexity: 

    Best Case - O(n logn) 

    Average Case - O(n logn) 

    Worst Case - O(n^2) 

Space Complexity - O(n)

3. Dijstra 

- Initialize the adjacency matrix and take user input for edges and weights.
- Set all distances to infinity (INT_MAX) except the source, which is set to 0.
- Use a boolean array to track visited nodes and prevent reprocessing.
- Select the unvisited node with the smallest distance in each iteration.
- Update distances of neighboring nodes if a shorter path is found.
- Store the shortest path for each node using a linked list.
- Print the shortest distances and paths from the source to all vertices.

Time Complexity - O(V^2)
Space Complexity - O(V^2)

4. Strassens 

- Strassen’s Algorithm is a fast matrix multiplication method using divide-and-conquer.
- It splits matrices into four equal submatrices recursively.
- Instead of 8 recursive multiplications, it computes 7 using special formulas.
- The algorithm reduces time complexity from O(n^3 ) to  O(n^2.81).
- It reconstructs the final matrix from intermediate results.
- Effective for large matrices but has high overhead for small sizes.

Time Comlexity - O(n^2.81)
Space Complexity - O(n^2)

## LAB 6

1. Kruskal 

- Sort the edges in ascending order of weight using a Min-Heap (build heap and heapify).
- Initialize parent array for union-find operations.
- Iterate through edges, extract the minimum edge, and find the roots of both vertices using the find() function.
- If the roots are different, include the edge in the MST, union the sets, and update the minimum cost.
- Repeat until (n-1) edges are selected or all edges are processed.
- If (n-1) edges are not found, print that a spanning tree does not exist.
- Print the MST edges and total weight.

Time Complexity - O(E logE) // Extracting Minimum Edge and Applying Heapify
Space Complexity - O(V + E) // Array size of V + Edge list of E edges


         
## LAB 9

1. Given an integer n, the task is to find the solution to the n-queens problem, where n queens are placed on an n*n chessboard such that no two queens can attack each other.

#### Algorithm: 
1.	Start with column 1 and try placing a queen in each row of that column.
2.	For each row, check if placing a queen there is safe (no other queen in the same row, main diagonal, or anti-diagonal).
3.	If safe, place the queen and mark the row and diagonals as occupied.
4.	Recur to place the queen in the next column.
5.	If a solution is found (column > n), store the current configuration.
6.	Backtrack: remove the queen and unmark the row and diagonals.
7.	Repeat until all solutions are explored.

#### Output:
Enter the value of n 
4
[2 4 1 3]
[3 1 4 2]
#### Time Complexity: O(N!) 
![alt text](Lab9\image.png)
#### Space Complexity: O(N)
