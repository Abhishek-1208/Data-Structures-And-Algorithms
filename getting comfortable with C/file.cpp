/**
 * program to read lines from input file and printing lines whose length is greater than 81
 * compilation: gcc program_to_read_lines_from_input_file_and_printin_lines_whose_length_is_greater_than_81.c
  Execution: Data-Structures-And-Algorithms/coding/program_to_read_lines_from_input_file_and_printin_lines_whose_length_is_greater_than_81.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/

#include <stdio.h>
int main() {
	
	FILE *fptr;
	//opening the file in which input is present
	fptr = fopen("E:/abhi/Documents/input.txt.txt","r");
	if (fptr == NULL) {
		printf("unable to  open file \n");
	    	return 0;
    	}
        char pos;
	do {
		int len = 0;
		char temp[1000];
		//inserting all characters until next line character is encountered or EOF 
		do{
			pos = fgetc(fptr);
			temp[len++] = pos;
		}while(pos != '\n' && pos != EOF);
		
		//if length of current line is greater than 80..print the content
		if(len > 80) {
			for(int i = 0; i < len; i++) {
				printf("%c", temp[i]);
			}
		}
		
	}while(pos != EOF);
	
	//closing the file
	fclose(fptr);
	
}
