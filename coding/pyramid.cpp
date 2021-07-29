#include <stdio.h>
int main() {
	printf("Enter height of pyramid: ");
	int height;
	scanf("%d", &height);
	
	for(int i = 1; i <= height; i++) {
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
