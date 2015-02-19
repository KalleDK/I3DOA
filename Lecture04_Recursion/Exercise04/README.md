# Exercise 4: A pattern of stars
Examine this pattern of stars and blanks, and design, implement, and test a recursive function that can generate patterns such as this: 

#### 1. State the problem in terms of its size/complexity



#### 2. Find, state and handle the base case (BC).
if (n == 0) then return

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
print_stars(n/2,i)
print " " i gange
print *   n gange
print_stars(n/2,n/2)

#### 4. Ensure that the RC reaches the BC
n is divided by 2 and will therefor end in n == 1, as n is a power of 2
