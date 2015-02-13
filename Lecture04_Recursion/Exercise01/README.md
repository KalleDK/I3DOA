# Exercise 1: Triangle
Design, implement, and test the function triangle() below.

```cpp
// Precondition: m <= n
// Postcondition: The function has printed a pattern of lines so that the
// first line contains m stars, the next line contains m+1 stars, and so on
// up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
// Example output:
// triangle( 4, 6) will print this:
// ****
// *****
// ******
// ******
// *****
// ****
//
void triangle(unsigned int m, unsigned int n)
```

#### 1. State the problem in terms of its size/complexity


#### 2. Find, state and handle the base case (BC).
m == n, print m starts x 2

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
print m stars
triangle(m+1,n)
print m stars

#### 4. Ensure that the RC reaches the BC
As m < n, and we keep calling triangle where we increment m will become n
