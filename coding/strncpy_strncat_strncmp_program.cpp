#include<stdio.h>
//return length of entered string as return value
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

int min(int a, int b) {
	return a <= b ? a: b;
}
int strlen(char *str) {
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}
	return len;
}

int strncpy(char *str1, char *str2, int n) {
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	n = min(n, min(len1, len2));
	
	for(int i = 0; i < n; i++) {
		str1[i] = str2[i];
	}
	
	str1[n] = '\0';
	return n;
	
}

int strncat(char *str1, char *str2, int n) {
	
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	n = min(n, len2);
	
	for(int i = 0; i < n; i++) {
		str1[len1++] = str2[i];
	}
	
	str1[len1] = '\0';
	return len1;
		
}

int strncmp(char *str1, char *str2, int n) {
	
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	n = min(n, min(len1, len2));
	for(int i = 0; i < n; i++) {
		if(str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}	
	}	
	if(len1 > n) {
		return str1[n];	
	}
	if(len2 > n) {
		return -str2[n];
	}
	
	return 0;
}

int main() {
	char str1[50], str2[50];
	
	printf("Enter the 1st string: ");
	int len1 = input_string(str1);
	
	printf("Enter the 2nd string: ");
	int len2 = input_string(str2);
	
	int status = strncmp(str1, str2, 5);
	if(status == 0 ){
		printf("strings are equal\n");
	}
	else if(status < 0) {
		printf("string1 is smaller than string2\n");
	}
	else {
		printf("stirng1 is greater than string2\n");
	}
	
	len1 = strncat(str1, str2, 5);
	printf("string1 after cancatenation becomes %s\n", str1);
	
	len1 = strncpy(str1, str2, 5);
	printf("string1 after copying becomes %s\n", str1);
	
}
