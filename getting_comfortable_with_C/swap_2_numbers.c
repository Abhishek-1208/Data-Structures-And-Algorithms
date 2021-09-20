/**
 *program to swap given 2 numbers without using 3rd variable
 * compilation: gcc swap_2_numbers.c
 * Execution: Data-Structures-And-Algorithms/coding/swap_2_numbers.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/
#include <stdio.h>

int main() {
	
	int a , b;
	printf("Enter the 2 numbers: ");
	scanf("%d %d", &a, &b);
	printf("number before swapping:\n a = %d \n b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;   // it becomes b = (a ^ b) ^b = a
	a = a ^ b;   // it becomes a = (a ^ b) ^a = b
	printf("number after swapping:\n a = %d \n b = %d", a, b);
}
