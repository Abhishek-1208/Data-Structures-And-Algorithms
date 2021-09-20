  
/**
 *program to count number of vowels and consonants(rest of values in string)
 * compilation: gcc vowels_and_consonants.c
 * Execution: Data-Structures-And-Algorithms/coding/vowels_and_consonants.c
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

//check if the passed character is vowel or not
int isVowel(char x, char *vowels) {
	for(int i = 0; i < 10; ++i) {
		// if x is equal to any of the 10 vowels ..return true
		if(vowels[i] == x) {
			return 1;
		}
	}
	//reaching here means it is not equal to any of vowel ..hence it is a consonants
	return 0;
}

int main() {
	
	char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	char str[50];
	printf("Enter the string: ");
	int len = input_string(str);
	
	int count_of_vowels = 0;
	
	for(int i = 0; i < len; i++) {
		//if the current character is vowel, increment the count
		if(isVowel(str[i], vowels))
			count_of_vowels++;
	}
	
	printf("Number of vowels are %d\nNumber of consonants are %d\n", count_of_vowels, len - count_of_vowels);
	
}
