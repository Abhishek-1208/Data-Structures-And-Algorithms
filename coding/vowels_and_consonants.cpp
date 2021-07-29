#include <stdio.h>



int isVowel(char x, char *vowels) {
	for(int i = 0; i < 10; ++i) {
		if(vowels[i] == x) {
			return 1;
		}
	}
	return 0;
}

int main() {
	char str[50], temp;
	char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
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
	
	int count_of_vowels = 0;
	
	for(int i = 0; i < len; i++) {
		if(isVowel(str[i], vowels))
			count_of_vowels++;
	}
	
	printf("Number of vowels are %d\nNumber of consonants are %d\n", count_of_vowels, len - count_of_vowels);
	
}
