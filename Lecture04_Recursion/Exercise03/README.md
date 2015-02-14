# Exercise 3: Booklet printing

Many printers allow booklet printing of large documents. When using booklet printing, 4 pages are printed on each sheet of paper, so that the output sheets can be folded into a booklet, see below 

#### 1. State the problem in terms of its size/complexity


#### 2. Find, state and handle the base case (BC).
Print startpage, startpage +1
Startpage >= Endpage - 3;
Print endpage-1, endpage

#### 3. Find, state and handle the recursive case (RC) and ensure progress towards the BC
Print Title startpage, startpage +1 endpage-1, endpage
print_booklet(startpage+2,endpage-2);

#### 4. Ensure that the RC reaches the BC
as we raise startpage with 2 end lower endpage with 2 each time, at some point Startpage >= Endpage - 3;
