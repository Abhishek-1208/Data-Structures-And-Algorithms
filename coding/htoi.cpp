#include <stdio.h>

//gives value cooresponding to given character
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
	
	//reaching here means the x is numeric value
	return x - '0';
	
}
int pow(int x, int y) {
	int num = 1;
	for(int i = 1; i <= y; i++) {
		num = num * 16;
	}
	return num;
}

int htoi(char *str, int len) {
	int num = 0;
	
	for(int i = len - 1; i >= 0; i--) {
		if(str[i] == 'x' || str[i] == 'X') {
			break;
		}
		else {
			num += pow(16, len - i - 1)*corr_val(str[i]);
		}	
	}
	
	return num;
}
int main() {
	char str[50], temp;
	printf("Enter the string: ");
	int len = 0;
	while(temp = getchar()) {
		if(temp =='\n') {
			str[len] ='\0';
			break;
		}
		else
			str[len++] = temp; 
	}
	
	int num = htoi(str, len);
	printf("number corresponding to hexadecimal %s in decimal form is %d\n", str, num);
	
}
