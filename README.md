# DynamicBitMap
Problem Statement: Implement bitfield functions,
=================

A function that sets a specific bit position in a bitmap
A function that clears a specific bit position in a bitmap
A function that checks if a specific bit position is set or not in a bitmap
 

Define suitable bitmap data-structure
Your bitmap should be able to support scale as big as in thousands.
Your bitmap should be able to grow dynamically (no need to shrink once grown).
 

Please implement in C language.

Please submit supported test-cases you would use to test your functions, including corner/negative cases.


Answer:
======
bitmap.h has a structure BitMap_t which has a integer pointer to point to dynamically allocated memory for storing bitmap , chosen integer pointer, so that it can hold 32 bits and actual length of dynamic memory , All the function proto types are defined

bitmap.c all functions are defined in this file and a main function to test various test cases 

Used dynamic memory to store the bitmap , realloc to grow memory dynamically if allocated memory is not sufficient to store the bit position

Used bitwise operators or(|), and(&), once complement(~) to set, check, reset bit position

Test cases:
==========

Set/reset a bit in various range and verify

1) set bit position 1, check bit 1 is set
2) clear bit position  1, check bit 1 is cleared
3) set bit position 100 , check bit 100 is set
4) clear bit position 100, check bit 100 is cleared
5) set bit position 1000, check bit 1000 is set
6) clear bit 1000, check bit 1000 is cleared
7) check bit 50000  before setting, bit 50000 should not be set, it should fail, because this bit position will not be available to reset  
8) set bit position 50000 , check bit position 50000 is set
9) set bit position -1, set should fail becacuse -1 is not a valid bit position
10) clear bit position 500 without setting, there should not be any error

Set multiple bit in combination and verify the result

11) set bit position 1 and 33, check both bits are set, verify when you extend the memory previously set bits are retained.
12) set bit 5 and 34, Memory should not be extended because these two bits are within already allocated memory range
13) set bit positions 1000,5000 check both bits are sets
14) reset bit 1 andd 33, check bits are cleared and bits 1000, 5000 should not cleared

Unit Test case Logs:
===================
root@admin1-08:~/smuthiah/DynamicBitMap# ./a.out 1 100 1000
	Setting 1th bit position 

	checking 1th bit position 
	1th bit position status  1 for set, 0 for not set: 1

	Clearing 1th bit position 
	checking 1th bit position after reset 

	1th bit position status  1 for set, 0 for not set: 0
	Setting 100th bit position 

Memory dynamically extended: new dynamic Array size : 16B
	checking 100th bit position 
	100th bit position status  1 for set, 0 for not set: 1

	Clearing 100th bit position 
	checking 100th bit position after reset 

	100th bit position status  1 for set, 0 for not set: 0
	Setting 1000th bit position 

Memory dynamically extended: new dynamic Array size : 140B
	checking 1000th bit position 
	1000th bit position status  1 for set, 0 for not set: 1

	Clearing 1000th bit position 
	checking 1000th bit position after reset 

	1000th bit position status  1 for set, 0 for not set: 0
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
2
root@admin1-08:~/smuthiah/DynamicBitMap# gcc bitmap.c 
root@admin1-08:~/smuthiah/DynamicBitMap# ./a.out 1 100 1000
	Setting 1th bit position 

	checking 1th bit position 
	1th bit position status  1 for set, 0 for not set: 1

	Clearing 1th bit position 
	checking 1th bit position after reset 

	1th bit position status  1 for set, 0 for not set: 0
	Setting 100th bit position 

Memory dynamically extended: new dynamic Array size : 16B

	checking 100th bit position 
	100th bit position status  1 for set, 0 for not set: 1

	Clearing 100th bit position 
	checking 100th bit position after reset 

	100th bit position status  1 for set, 0 for not set: 0
	Setting 1000th bit position 

Memory dynamically extended: new dynamic Array size : 140B

	checking 1000th bit position 
	1000th bit position status  1 for set, 0 for not set: 1

	Clearing 1000th bit position 
	checking 1000th bit position after reset 

	1000th bit position status  1 for set, 0 for not set: 0
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

5000
	checking 5000th bit position 
bitposition 5000 is beyond the bitmap size 140 
bit position check is failed 
	5000th bit position status  1 for set, 0 for not set: -1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

50000
Memory dynamically extended: new dynamic Array size : 6388B

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

50000
	checking 50000th bit position 
	50000th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

-1
Bit position can't be less than zero -1
BitMapSet is failed 
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

500
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

3
	Enter the bit position to be cleared 
500
	Clearing 500th bit position 
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

3
	Enter the bit position to be cleared 
5000
	Clearing 5000th bit position 
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

1
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

33
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

1
	checking 1th bit position 
	1th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

33
	checking 33th bit position 
	33th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

1000
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

1
	Enter the bit position to be set 

5000
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

33
	checking 33th bit position 
	33th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

5000
	checking 5000th bit position 
	5000th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

3
	Enter the bit position to be cleared 
1000
	Clearing 1000th bit position 
	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
1
	Choose the bit operation from Menu 

	Enter 1 for set bit, 2 for check whether bit is set, 3 for clear the bit: 

2
	Enter the bit position to check

33
	checking 33th bit position 
	33th bit position status  1 for set, 0 for not set: 1

	Do you wanted to continue further testing: enter 1 to continue/ 2 to exit 
2
root@admin1-08:~/smuthiah/DynamicBitMap
