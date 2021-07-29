//program to print pyramid of given length
#include <stdio.h>
int main() {
	printf("Enter height of pyramid: ");
	int height;
	scanf("%d", &height);
	
	for(int i = 1; i <= height; i++) {
		//printing the ith line of pyramind after printing required number of spaces
		
		for(int space = 1; space <= height - i; space++) {
			printf(" ");
		}
		
		for(int count = 1; count <= i; count++) {
			printf("# ");
		}
		
		for(int space = 1; space < height - i; space++) {
			printf(" ");
		}
		
		printf("\n");
	}
	
}
