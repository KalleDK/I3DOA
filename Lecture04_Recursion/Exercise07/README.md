# Exercise 7: Is my phone number cool?
When you send text messages you may use the mobile phone’s digits for letters, i.e. characters ‘d’, ‘e’, and ‘f’ are on digit ‘3’.

#### 1. State the problem in terms of its size/complexity


#### 2. Find, state and handle the base case (BC).
size == 0
print whole string

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
for each letter in digit
	string[full_length-size] = letter
	print_phone(number+1, size-1, string, full_length)

#### 4. Ensure that the RC reaches the BC
We keep decreasing size, so it will end on 0 at some point
