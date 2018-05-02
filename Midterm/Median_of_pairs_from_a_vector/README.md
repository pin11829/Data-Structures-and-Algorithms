# Median_of_pairs_from_a_vector
------

(40 pts) **Median of pairs from a vector**:

Given a vector of n integers a= {a1 ,a2 ,...,an },we can form a pair sum vector **b** of m(= n(n−1)/2) elements by selecting any 2 elements from vector a and use their sums as elements.
In other words, the elements of **b** can be described by the multi-set (which is a set that allows multiple instances of same-value elements ):

{ai + aj|1 ≤ i < j ≤ n}

Please find the median of these m pair sums. Note that the median of a vector is the middle number after the vector is sorted. (Here we suppose the given n can always make m an odd number.)

More details:

* Input format:
  * Line 1 is an integer id (1 ≤ id ≤ 6) indicating the subtask ID (to be defined later).
  * Line 2 is an integer nindicating the length of the vector a.
  * Line 3 lists the vector's nelements separated by a space.

* Output format:
  * The median

* Ranges of variables:
  * n≤ 2 × 106 .
  * 0≤ai ≤109,∀i.
  * Others to be defined for each subtask explained below.

* Example test case:
  * Input

    2

    6

    880301
  * Output

    8
  * Explanation of the above test case
    * 2 in line 1 of the input indicates the test set satisfies test group 2, where n≤ 1000
    * 6 in line 2 of the input indicates the vector has 6 elements, as listed in line 3.
    * Since the sums of all these 15 pairs are 0,1,1,3,3,4,8,8,8,8,9,9,11,11,16, their median is 8.

* Subtask descriptions: To facilitate partial credit, we use subtask ID to indicate subtasks of different degrees of difficulty, as follows.
  * id = 1 (8 pts): n≤ 2 × 100000, and all elements in the vector has only a single value.
  * id=2(8pts):n≤1000.
  * id = 3(8pts):n≤2×100000 ,andallelementsinthevectorhasonly two distinct values.
  * id = 4(8pts):n≤2×100000,and 0 ≤ai ≤10 ,∀i.
  * id = 5(4pts):n≤2×100000 .
  * id = 6 (4 pts): No restrictions.
