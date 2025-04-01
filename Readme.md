# Analysis and Design Algorithm

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

Time Complexity - O()

3. Magic Square for ODD matrix

- Initialize an n × n matrix with all elements as 0.
- Start at (0, n/2) and loop from 1 to n*n.
- Place i at arr[row][col] and compute next position.
- If next cell is occupied, move down, else move diagonally up-left.
- Repeat until the matrix is filled, then print the magic square.

Time Complexity - O(n^2)
Space Complexity - O(n^2)

4. F