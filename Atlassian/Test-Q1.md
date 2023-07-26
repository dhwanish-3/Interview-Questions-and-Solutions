## Question 1

Given an array of n integers, make the array positive with the following operations:

In one operation, select integers i (0 <= i < n) and x (-10^18 <= x <= 10^18) and change arr[i] to x.

An array is positive when the sum of each subarray of length greater than 1 is non-negative. More formally, after the operations, the following conditions should hold for all values of l and r.

0 <= l < r < n  sum of all arr[i] from i = l to r >= 0

Determine the minimum number of operations required to make the array positive.

Constraints:
1. 1 <= n <= 10^5
2. -10^9 <= arr[i] <= 10^9 , where 0 <= i < n

Sample Case 0:
n = 5
arr = [-1, -1, -1, -1, -1]

Sample Output 0:
2

Sample Case 1:
n = 6
arr = [6, -5, 5, 20, -1]

Sample Output 1:
0