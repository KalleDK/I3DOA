# Exercise 2: Searching an array
Design, implement, and test a recursive function that searches through the first n elements of an array ar of integers for a given element x. If x is found in ar[0..n) the element is found, the function should return true, else the function should return false.

#### 1. State the problem in terms of its size/complexity
Funktionen kigger fra plads  0 til plads n-1 i arrayet for elementet x, hvis den findes returneres true ellers false.


#### 2. Find, state and handle the base case (BC).
if ar[n] == x then
	return true
else if n == 0
	return false

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
recursice_search(ar, n-1, x)

#### 4. Ensure that the RC reaches the BC
Either the object is found or n-1 will make n become 0
