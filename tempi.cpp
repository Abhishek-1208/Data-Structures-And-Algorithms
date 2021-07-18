#include <stdio.h>
#include <math.h>
double adjustPrecision(double num, int precision) {
	return floor(pow(10, precision) * num) / pow(10, precision);
}
int main() {
	int num, precision;
	printf("Enter the Number: ");
	scanf("%d", &num);
	printf("Enter the precision upto which you want to calculate square root of num : ");
	scanf("%d", &precision);
	
	int low = 0, high = num;
	while(low <= high) {
		int guess = low + (high - low) / 2;
		if(guess * guess <= num) {
			low = guess + 1;
		}
		else {
			high = guess - 1;
		}
	}
	
	double ans = low - 1;
	double addingFactor = 0.1;
	for(int digit = 1; digit <= precision; digit++, addingFactor /= 10) {
		while(ans * ans <= num) {
			ans += addingFactor;
		}
		ans -= addingFactor;
	}
	
	printf("Square root of %d is %lf", num, adjustPrecision(ans,precision));
	
}
