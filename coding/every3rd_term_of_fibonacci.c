/**
 * program to solve tower of hanoi puzzle
 * compilation: gcc toh.c
 * Execution: Data-Structures-And-Algorithms/coding/toh.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 5
*/


#include <stdio.h>

// recursive function to print the steps and count total moves
int TOH(int n, char src, char aux, char des) {
	int moves = 0;
	if(n >= 1) {
		moves += TOH(n - 1, src, des, aux);
		printf("%c to %c\n", src, des);
		moves += TOH(n - 1,aux, src, des);
		moves++;
	}
	return moves;
}

int main() {
	int n;
	printf("Enter the number of rings in the first tower: ");
	scanf("%d", &n);
	int moves = TOH(n, 'A', 'B', 'C');
	printf("total moves taken are %d \n", moves);
	
	
}
