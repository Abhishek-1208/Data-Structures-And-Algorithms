/**
 * program to find greatest common divisor of 2 numbers
 * compilation: gcc gcd.c
 * Execution: Data-Structures-And-Algorithms/coding/gcd.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 5
*/

#include <stdio.h>

//function to find gcd of two given numbers
// Time: O(log N)
// Space: O(1)
int gcd(int a, int b) {
	
	if(b == 0)
		return a;
	//since gcd is not get affected by % operator so we are using modulo operator instead of subtraction	
	return gcd(b, a % b);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("Gcd of given two numbers is %d\n", gcd(a, b));
}
