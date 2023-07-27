## Qustion 1

Given an integer n and an array of size n. An array new_arr is created such that,

1. 0 < new_arr[i] <= arr[i] for 0 <= i < n

2. no 2 elements can be same

Find the number of such new_arr

since the output can be very large return the value mod 1e9 + 7 .

Sample Test 1:
n = 3
arr = [1, 2, 3]

Sample Output:
1

Sample Test 2:
n = 3
arr = [1, 2, 1]

Sample Output:
0