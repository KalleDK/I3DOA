# Exercise 6: Binary search algorithm
Design, implement and test binary search of a sorted array as we have discussed in class. Also implement serial search.  Run binary and serial search on large arrays (e.g of size 2000 and greater) and compare their execution times – is binary search worthwhile?

#### 1. State the problem in terms of its size/complexity

#### 2. Find, state and handle the base case (BC).
if (base[i] == x) return true
if (i == 0) return false

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
i = size / 2
if (base[i] > x)
	return binsearch(base+i+1, i)
else
	return binsearch(base, i)

#### 4. Ensure that the RC reaches the BC
we devide the size by 2 each time.. at some point we will get 0

#### 5. Is it worth it
Going from O(N) to O(log N) is well worth it
