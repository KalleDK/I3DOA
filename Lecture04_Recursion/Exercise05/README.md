# Exercise 5: A recursive Linked List Toolkit

#### 1 Which functions can be recursive
Review your linked list toolkit. Which of the functions in the toolkit may be implemented recursively? Ask yourself: “Can I solve this problem by solving a smaller version of it?”
* copy
* clear
* print
* reverse (but not worth it)
* build
* join (a close case, did it for fun)
* rotateLeft & Right (but not worth it)

#### 2 State the 4 cases to make a recursive function
For each of the functions you found in (1) above, state the base case and the recursive case, and argue that the algorithm is correct (i.e., that it does what it is supposed to do, and that it terminates)

##### 1. State the problem in terms of its size/complexity

##### 2. Find, state and handle the base case (BC).
###### copy
if sourcePtr == NULL return NULL

###### clear
if headPtr == NULL return

###### print
if headPtr == NULL print /

###### build
if n == 0 return NULL;

###### join
if head1->next == NULL then head1->next = head2


##### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
###### copy
new Node = Source->info
Node->next = copy(sourcePre->next)
return Node

###### clear
headRemove(head)
clear(head)

###### print
cout head->info
print(head->next)

###### build
new Node = Ar[0]
Node->next = build(Ar+1, n-1)

###### join
join(head1->next, head2)

##### 4. Ensure that the RC reaches the BC
###### copy
As we keep calling copy with the next element, we would end with head1->next == NULL at some point

###### clear
We remove the head and call the function with the rest, at some point we got NULL in head

###### print
We keep calling print with the next element in the chain, at some point head == NULL

###### build
We keep decreasing n at some point it will be 0

###### join
we keep calling join with the next element at some point head1->next will be NULL

#### 3. Design, implement and test your recursive solutions from (1) and (2) above.
Done
