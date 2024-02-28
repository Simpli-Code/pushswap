# pushswap
Here, I will briefly describe the algorithm that used for my push_swap project:

In my implementation, I use a linked list for sorting the numbers and an integer array for filtering the numbers for validity, so the algorithm can also be implemented with  arrays, if you adapt this algorithm with some modifications. After filtering the input for validity (checking if the input are valid integers or there are no duplication) then I split and convert the input string into integers using my functions ft_split(); and ft_atoi(); then I store each value in a separate node in a singly linked lists (aka STACK A).

The goal is to sort the input (which are numbers between MIN INT AND MAX INT) in ascending order into STACK A.

To do so you have the following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.

Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.

Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.

Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.

The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.

The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.

The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.

The last element becomes the first one.

rrr : rra and rrb at the same time.

After filling up my STACK A with random numbers that I received as input I have the above instructions to sort my STACK A, so in order to achive that I create another stack which will be STACK B. 


# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Instructions

Compiling the program

$ make

Executing the program

$ ./push_swap "5 -9 2 -1" 99 -42 6

# 📑 Index
@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.

Note: This program covers only mandatory requirements of the project's subject.
