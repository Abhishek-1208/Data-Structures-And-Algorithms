#include <stdio.h>

int main() {
	
	int a , b;
	printf("Enter the 2 numbers: ");
	scanf("%d %d", &a, &b);
	printf("number before swapping:\n a = %d \n b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("number after swapping:\n a = %d \n b = %d", a, b);
}
