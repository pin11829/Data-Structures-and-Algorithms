# Smallest K elements in a vector
------

(30 pts) **Smallest K elements in a vector**:

You are given a vector of N 32-bit signed integers. Find the first K smallest elements, and output them from the biggest to the smallest.

More details:

* Input format:
  * Line 1 is an integer T indicating the number of test cases.
  * T test cases follow, where each test case is composed of two lines.
    * The first line of the test case contains two positive integers, N and K, with K <= N.
    * The second line of the test case contains N integers of the vector.

* Output format:
  * For every test case, output one line with K integers, that is, the first K smallest elements of the vector ordered from the biggest to the smallest.

* Ranges of variables:
  * K ≤ N ≤ 106 .

* Example test case: Sample input
  2
  53
  -3 -1 0 7 9
  10 3
  32 89 0 12 -11 32 -5 -11 91 7

* Sample output:
  0 -1 -3
  -5 -11 -11

* Subtask descriptions
  1. T≤100,N≤1000 ,K≤100 (6pts)
  2. T≤50,N≤100000,K≤10000 (3pts)
  3. T ≤ 5, K = 1 (3 pts)
  4. T ≤ 5, K = 2 (3 pts)
  5. T ≤ 5, K ≤ 10000 (6 pts)
  6. T≤2(9pts)
