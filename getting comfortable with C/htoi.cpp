/**
 * program to convert hexadecimal to decimal number
 * compilation: gcc program to convert hexadecimal to decimal number.c
  Execution: Data-Structures-And-Algorithms/coding/program to convert hexadecimal to decimal number.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/

#include <stdio.h>

//return length of entered string as return value after taking input from user
int input_string(char *str)  {
	char temp;
	int len = 0;
	while(temp = getchar()) {
		if(temp =='\n') {
			str[len] ='\0';
			break;
		}
		else
			str[len++] = temp; 
	}
	return len;
}

//give the value in decimal representation cooresponding to given hexadeciaml character
int corr_val(char x) {
	
	if(x == 'a' || x == 'A') {
		return 10;
	}
	if(x == 'b' || x == 'B') {
		return 11;
	}
	if(x == 'c' || x == 'C') {
		return 12;
	}
	if(x == 'd' || x == 'D') {
		return 13;
	}
	if(x == 'e' || x == 'E') {
		return 14;
	}
	if(x == 'f' || x == 'F') {
		return 15;
	}
	
	//reaching here means that x is numeric value
	return x - '0';
	
}
//function to calculate x raise to power y
int pow(int x, int y) {
	int num = 1;
	for(int i = 1; i <= y; i++) {
		num = num * 16;
	}
	return num;
}

//auxillary function to convert hexadecimal string to its decimal value
int htoi(char *str, int len) {
	int num = 0;
	
	for(int i = len - 1; i >= 0; i--) {
		// str[i] == x or X means we have processes all the characters
		if(str[i] == 'x' || str[i] == 'X') {
			break;
		}
		//adding the contribution of current character to the final result
		else {
			num += pow(16, len - i - 1)*corr_val(str[i]);
		}	
		
	}
	
	return num;
}
int main() {
	char str[50], temp;
	printf("Enter the string: ");
	int len = input_string(str);
	
	//calling function to get value corresponding to given hexadecimal number
	int num = htoi(str, len);
	printf("number corresponding to hexadecimal %s in decimal form is %d\n", str, num);
	
}
