//program to implement the standard string.h library functions such as strncpy , strncat, strncmp
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
//function to return the minimum of passed 2 variable
int min(int a, int b) {
	return a <= b ? a: b;
}
//function to calculate length of passed array
int strlen(char *str) {
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}
	return len;
}
//function to implement the strncpy function which copies the first n characters of str2 to str1
//returns the length of modified string
int strncpy(char *str1, char *str2, int n) {
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//finding the minimum number of character that str1 can hold..this condition is necessary to avoid overflow incase len1 and n are way larger than len1
	n = min(n, min(len1, len2));
	//copying the character of str2 to str1 one by one
	for(int i = 0; i < n; i++) {
		str1[i] = str2[i];
	}
	
	str1[n] = '\0';
	return n;
	
}
//function to implement strncat which concatenate the first n characters from str2 to the end of str1
//returns the length of modified string
int strncat(char *str1, char *str2, int n) {
	
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	n = min(n, len2);
	//concatenating the first n characters of str2 at the end of str1
	for(int i = 0; i < n; i++) {
		str1[len1++] = str2[i];
	}
	
	str1[len1] = '\0';
	return len1;
		
}

//function to implement the strncmp function which compares 2 strings upto first n characters 
//returns 0 if str1 == str2 or some (x >0) if str1 > str2 or some (x<0) if str1 < str2 
int strncmp(char *str1, char *str2, int n) {
	
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	n = min(n, min(len1, len2));
	for(int i = 0; i < n; i++) {
		//incase characters are not matching ..return the difference between their ascii value
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
	
	//checking whether the passed 2 strings are equal or not upto 5 characters
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
	
	//to check the correct working of strncat function
	len1 = strncat(str1, str2, 5);
	printf("string1 after cancatenation becomes %s\n", str1);
	
	//to check the correct working of strncpy function
	len1 = strncpy(str1, str2, 5);
	printf("string1 after copying becomes %s\n", str1);
	
}
