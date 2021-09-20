/**
 * program to convert given reverse polish expression to infix expression
 * compilation: gcc reverse_polish_to_infix_expression.c
 * Execution: Data-Structures-And-Algorithms/coding/reverse_polish_to_infix_expression.c

 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
 *
 * Note: I have implemented the whole string and stack class just like c++ to ease the remaining task 
 *       and so as to improve readability of code.. so i have used most latest version of c language ..\
 *       if any error comes ..please try using latest version  or change the extension to .cpp

*/

#include <stdio.h>
#include <stdlib.h>
//function to take string as input from user until end of line is encountered
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

// returns true if x is an operator
int is_operator(char x) {
   return x == '/' || x == '*' || x == '+' || x == '-';
}



//implementing the string strucuture so that it becomes easy to deal with the problem

// init() : initialize the string with some predefined size
// push_back(char x) : push the character x to the end of string
// pop_back() : deletes the last character
// size():  returns the size of string
// append(string temp) : append string temp to the end of main string
// put(string temp) : changes value of the string to temp i.e string becomes equal to temp
// clear() : clear the whole string
// print() : print the content of the string
// valueAt(int index) : return the character present at index... i.e str[index]

struct string{
	char *str;
	int len;
	string() {
		str = (char *)malloc(50 * sizeof(char));
		len = 0;
	}
	
	void init() {
		str = (char *)malloc(50 * sizeof(char));
		len = 0;
	}
	
	void push_back(char x) {
		str[len++] = x;
	}
	void pop_back() {
		len--;
	}
	int size() {
		return len;
	}
	int valueAt(int index) {
		return str[index];
	}
	void append(string temp) {
		for(int i = 0; i < temp.size(); i++) {
			str[len++] = temp.valueAt(i);
		}
	}
	void put(string temp) {
		for(len = 0; len < temp.size(); len++) {
			char x = temp.valueAt(len);
			str[len] = x;
		}
	}
	void clear() {
		len = 0;
	}
	void print() {
		for(int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	
};

// implementing our own stack struct as well to ease make the main conversion function more readable
// pop() : deletes the top element from the stack
// top() : returns the top element from the stack
// push(string temp): push the string temp to the top of stack

struct stack {
	string *arr;
	int idx; 
	stack(int size) {
		arr = (string *)malloc(size * sizeof(string));
		for(int i = 0; i < size; i++) {
			arr[i].init();
		}
		idx = 0;
	}
	
	void pop() {
		idx--;
		arr[idx].clear();
	}
	
	string top() {
		return arr[idx - 1];
	}
	
	void push(string x) {
		arr[idx].put(x);
		idx++;	
	}

};



//auxillary function to convert reverse polish expression to infix expression
struct string reverse_polish_to_infix(char *str, int len) {
    
	//intializing a stack
	struct stack st(len);
	
	for(int i = 0; i < len; i++) {
		
		if(str[i] == ' ')
			continue;
		
		//to peform the current operand.. we need 2 values so we will take 2 values from stack and concatenate them 
		//then again push the final value to stack for future operations
		if(is_operator(str[i])) {
			struct string op1 = st.top();
            st.pop();
            struct string op2 = st.top();
            st.pop();
            struct string res;
            res.push_back('(');
            res.append(op2);
            res.push_back(str[i]);
            res.append(op1);
            res.push_back(')');
            st.push(res);
        }
	    
	    //if current character is not an operator ..simply push it to stack
	    else {
	    	struct string temp;
	    	temp.push_back(str[i]);
	    	st.push(temp);
		}
	    
	}
	
	//returning the result which will be present at the top of the stack
	return st.top();
	
}


int main() {
	char str[50];
	printf("Enter the reverse polish expression: ");
	int len = input_string(str);
	
	//to store the final result
	struct string res;
	
	//	putting the value returned by function to res
	res.put(reverse_polish_to_infix(str, len));
	
	printf("Expression becomes: ");
	
	// function to print the final expression as a string
	res.print();
	
}
