# pushswap
Here, I will briefly describe the algorithim that used for my push_swap project:

In my implementation, I use a linked list for sorting the numbers and an integer array for filtering the numbers for validity, so the algorithm can also be implemented with  arrays, if you adapt this algorithm with some modifications. After filtering the input for validity (checking if the input are valid integers or there are no duplication or the input is not sorted (numbers are not in ascending orders)) then I split and convert the input string into integers using my functions ft_split(); and ft_atoi(); then I store each value in a separate node in a singly linked lists (aka STACK A).

The goal is to sort the input (which are numbers between MIN INT AND MAX INT) in ascending order into STACK A.

To do so we are only allowd to use the following operations:

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

After filling up the STACK A with random numbers that we received as input we have the above instructions to sort the STACK A, so in order to achive that we have to create another stack which will be called STACK B. Depending on the number of inputs or number of elements we receive, which will define our stack size, we will react with different methods to sort the STACK A. So in another words before we proceed with sorting we have to always check our stack size first. For example if we have two elements (stack size == 2) which are not sorted, we just need to swap them or if we have three elements (stack size == 3) we call our function sort_3_elements(); or sort_5_elements(); for sorting a stack size of 5, so if we have a stack size of up to 5 elements we call specific function to handle these cases, our sorting algorithm will be called when we have more than 5 elements in our stack. So now let's assume that we receive an input of 250 elements, so our STACK A contains 250 unsorted numbers and our STACK B is yet empty, how do we proceed with sorting this elements?

In order to fully grasp the logic behind this algorithim, we have to go one step back. As I mentioned befor I store the input first in an integer array and check for validity of the input and after that I create a linked list and transfer the integer array to the linked list, so that each node contains one element of the integer array after doing that there will be no need of the integer array, and since I allocated the memory for the integer array dynamically, I need to free the memory, but before freeing the memory we need one more thing to do, we need the index of each element and since we are not allowed to manipulate the randomness of input, so we can not touch our STACK A, so therefor before freeing the integer array, we do one more operation on our integer array to extract the index of each elements which we will need for our selection algorithim. (NOTE: that we do this AFTER filling our STACK A) In order to get the index of each elements we use our bubble_sort(); function on our integer array, so now our integer array is sorted in ascending order and our STACK A is filled with the original unsorted input, so now we just need to compare each elements of our STACK A with our sorted integer array and assign an index to each elements of our STACK A.

So now we can continue with the example before of STACK A containing 250 elements:

What we do first is to divide our STACK A into chunks of elements, depending on the size of the stack if the stack size is less than 100 we use a chunk size of 15 and if the stack size is bigger than 100 we use a chunk size of 30, by try and error method it turned out that these chunk sizes worked the best. So now that we have the index of each elements and a fixed chunk size and the stack size, we can proceed with sorting our STACK A.

So the following method will remain the same as long as the stack size is bigger than 5 elements:

We set first a counter variable i to 0, and the chunk which we will call limit variable depending on the stack size either to 15 or 30, and then loop through each elements of our STACK A and check for the following 3 conditions:

1. if the current element's index is smaller or equal to i
      push the current element to STACK B and rotate it in STACK B and increment i value

3. if the current element's index is smaller or equal to i plus limit
      push the current element to STACK B and increment i value

5. if none of the previous conditions were true 
      rotate the current element in STACK A
   
When the loop reaches the end of STACK A, it means all the elements are pushed and presorted to STACK B, so now we proceed with the sorting in STACK B. 

We set first 3 integer variable biggest, half and position, and then simply loop through each elements of STACK B and check for the following 3 conditions:

1. if the current element's index is equal to to the biggest element
         push the current element to STACK A and decrease the variable biggest
3. if the current element's positon is in the lower half of STACK B and it is not the biggest element
         rotate the current element in STACK B
5. if the current element's position is in the upper half of the STACK B and it is not the biggest element
         reverse rotate the current element in STACK B

After this loop reaches the end every element will be pushed and sorted in STACK A.

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
