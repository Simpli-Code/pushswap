# pushswap
Here, I will briefly describe the selection algorithm for the push_swap project:

In my implementation, I use a linked list for sorting algorithm and an integer array for filtering the input for validity, so the algorithm can also be implemented with  arrays, if you adapt this algorithm with some modifications. After filtering the input for validity (checking if the input is a valid integer or there is no duplication) and then I convert the input string to integers using my function ft_atoi(); then I store each value in a separate node in a singly linked lists (aka STACK A).  so now I have filled up my STACK A with input the goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

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

# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Instructions

Compiling the program

$ make

Executing the program

$ ./push_swap "34562 -534093 2 -6" 99 -234243 644

# 📑 Index
@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.

Note: This program covers only mandatory requirements of the project's subject.
