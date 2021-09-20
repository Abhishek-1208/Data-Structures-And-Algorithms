/**
 * program to compute square root of a number with given precision
 * compilation: gcc file_name.c
 * Execution: Data-Structures-And-Algorithms/coding/squareRoot.c
 * @Abhishek (1910991168) 
 *19/07/2021
Assignemnt: 1
*/


#include <stdio.h>

/**
 *Auxillary function to calculate square root of number with precision
 * num: number whose sqrt we want to find
 *precision: precision upto which we want to calculate precision
 */
double square_root_using_binary_search(int num, int precision) {
    double epsilon = 1;
    //calculating the precision required
    for(int i = 0; i < precision; i++) {
     epsilon /= 10.0;
    }
    
    double low = 0, high = num;

    //binary searching on low and high
    while( (high - low ) > epsilon ){
        
	double mid = (low + high) / 2.0;
        //initial guess is mid
	
	if(mid * mid <= num) {
	   low = mid;
	}

	else {
	   high = mid;
	}

    }
    
    return low;

}

int main() {
    int num, precision;
    printf("Enter The Number: ");
    scanf("%d", &num);
    printf("Enter The Precision: ");
    scanf("%d", &precision);
    double sqr_root = square_root_using_binary_search(num, precision);
    printf("Square Root of %d is %.*f\n", num, sqr_root); 
}

