# Removing_same-value_neighboring_pairs_from_a_vector
------

(30 pts) **Removing same-value neighboring pairs from a vector:**

Given avector of nintegers {a , a , ... , a }, we want to remove same-value 12n neighboring pairs by performing the following operations:

  a. Scan the vector from left to right until we locate two same-value neighboring integers.

  b. Remove these two integers from the vector.

  c. Repeat the above two steps until there are no same-value neighboring elements.

Please output the final vector (from left to right).

More details:

* Input format:
  * Line 1 is an integer n, the length of the vector.
  * Line 2 contains nintegers of the vector's elements.

  * Output format: The output is a single line containing the final vector, with neighboring elements separated by a single space. In particular, if the result is an empty vector, please print "Meow" (without double quotes) instead.

  * Ranges of variables:
    * 1 ≤ n≤ 106
    * 1≤ai ≤106,∀i.

  * Example test cases:
    1. Case 1:
      * Sample input:

        2

        1 1
      * Sample output:
        Meow
    2. Case 2:
      * Sample input:

        4

        1 1 2 3
      * Sample output:

        2 3

  * Subtask descriptions:
    * n= 1==>2pts
    * n= 2==>2pts
    * n= 3==>4pts
    * a1 = a2 = ⋯= an==>2pts
    * 1≤n≤103 ==>10pts
    * 1≤n≤106 ==>10pts
