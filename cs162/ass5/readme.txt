//readme.txt

Hello TA or whoever else!!!

This program creates a linked list of nodes that contain elements of data that 
are of integer type. The user enters in the data, decides where it goes in the 
list, determines how many times to add another element, and what order the list
will be printed in by the end. The keyword to start the program is "./sort"

1. Enter an Integer 

	Here the user enters an integer for the first element

	The length is also printed at the beginning of each entry of data along
	with what the current list looks like. The user must enter an integer 
	and is prompted with an "Invalid input" for and invalid input.

2. Want to enter at front, back, or insert at a given index?

	Here the user will enter either 1, 2, or 3 for push_front, push_back,
	and insert repsectively

	If the user enters an invalid input, they will be prompted again. For 
	push_front the previous data becomes the new beginning and for push_back
	it becomes the new tail.

2b. Insert is chosen (3)

	If the length of the list is already 0, the program will automatically 
	input it into the empty list
	
	Otherwise, the user will be prompted to enter an index for the data to 
	be placed in. The indexing starts at 0 and goes to the end of the list+1
	This is to account for the data to be put at the end.

3. Add another number?

	The user will enter 1 for yes, and 0 for no.

	If yes, the process repeats itself. If no, the program will continue

4. List in ascending of descending order?

	The user will enter either 1 or 0 for the order.
	1 corresponds to ascending and 0 for descending. Both sorting algorithms
	use merge sort. The final list is also printed prior to this.

5. Printed

	The final order list is printed and the number of prime numbers is 
	displayed.


