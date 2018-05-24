# How’s Problem

**Problem definition**

You will be given an initial string S and an integer Q.

There are Q questions, and every question is in one of three forms, as shown below:

Form 1: 「1 c」 where c is a character added to the front of string S

Form 2: 「2 c」where c is a character added to the back of string S

Form 3: 「3 Ti」 where Ti is a string; output the number of occurrences of Ti in S

For example, suppose that initially, S = ”cd” and Q = 5. Five sequentially listed I/O operations are as follows.

1 'b' → now S = "bcd"

1 'a' → now  S = "abcd"

2 'e' → now S = "abcde"

3 "cd" → where, as before, S = "abcde"，"cd" appears once in S, and thereby ‘1’ is outputted

3 "aa" → where, as before, S = "abcde", S does not contain an instance of "aa", and ‘0’ is outputted.

---

* Input/Output Format

	Use stdin and stdout for input and output, respectively.
	
	The first line’s input is stored in string S, as stated above.
	
	The second line has integer Q, representing the amount of questions.
	
	Each of the following Q lines of input will appear in one of three forms:「1 c」,	「2 c」, or「3 Ti」, where c is a character and Ti is a string

---

* Subtasks
	* All subtasks may be satisfied by the following conditions:
	
		All characters are English alphabet lower-case characters
	
		1 ≤ initial length of string S ≤ 105
	
		1 ≤ Q ≤ 105 
	
		0 ≤ the sum of lengths of all strings Ti ≤ 105

	* Subtask 1 (5 pt):
	
		1 ≤ the initial length of string S ≤ 105
	
		Q = 1
	
		All questions are in the 3rd form

	* Subtask 2 (5 pt):
	
		1 ≤ the initial length of string S ≤ 1000
	
		1 ≤ Q ≤ 1000
	
		0 ≤ the sum of lengths of all strings Ti ≤ 104

	* Subtask 3 (30 pt):
	
		1 ≤ the initial length of string S ≤ 105 
	
		1 ≤ Q ≤ 105 
	
		The length of all strings Ti ≥ 104 
	
		0 ≤ the sum of lengths of all strings Ti ≤ 105

	* Subtask 4 (30 pt):
	
		1 ≤ the initial length of string S ≤ 105 
	
		1 ≤ Q ≤ 105 
	
		1 ≤ The length of all strings Ti ≤ 10 
	
		0 ≤ the sum of lengths of all strings Ti ≤ 105
	
	* Subtask 5 (30 pt):
	
		Original conditions (without optimization)
	
		1 ≤ the initial length of string S ≤ 105
	
		0 ≤ the sum of lengths of all strings Ti ≤ 105