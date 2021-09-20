/**
 * program to implement our own stack 
 * compilation: gcc stack.c
 * Execution: Data-Structures-And-Algorithms/coding/stack.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 6
*/

#include <stdio.h>
#include<stdlib.h>

//structure to represent our stack
struct stack {
	int top, capacity, *arr;
};

//initializing our stack
struct stack* init() {
	struct stack *st = ( struct stack *)malloc(sizeof( struct stack));
	st -> arr = (int *)malloc(5 * sizeof(int));
	st -> capacity = 5;
	st -> top = 0;
	return st;
}


//resizing in case our stack has reached its maximum capacity
void resize(struct stack *st) {
	
	st = realloc(st, st -> capacity * 2);
	st -> capacity *= 2;
}

//to check if stack is empty or not
int empty(struct stack *st) {
	return st -> top == 0;
}

//to get current size of stack
int size(struct stack *st) {
	return st -> top;
}
//to chek if the stack has reached its maximum capacity or not
int full(struct stack *st) {
	return st -> top == st -> capacity;
}

//to push the element to the top of stack
void push(struct stack *st, int x) {
	//resize first if stack is full
	if(full(st)) {
		resize(st);
	}
	st -> arr[st -> top] = x;
	st -> top++;
}

//to pop the element at top
void pop(struct stack *st) {
	//first check if stack is empty
	if(empty(st)) {
		printf("stack underflow\n");
		exit(1);
	}
	else {
		st -> top--;
	}
	
}

//to get the top element of stack
int top(struct stack *st) {
	//check first if stack is empty or not
	if(empty(st)) {
		printf("Error!...stack is empty\n");
		exit(1);
	}
	else {
		return st -> arr[st -> top - 1];
	}
}


int main() {
	struct stack *st;
	st = init();
	
	int n;
	printf("Enter the number of operations: ");
	scanf("%d", &n);
	
	//interface to work with our stack data structure
	while(n--) {
		printf("press 1 to insert\n");
		printf("press 2 to delete\n");
		printf("press 3 to get top element\n");
		printf("enter your choice: ");
		int user_inp;
		scanf("%d", &user_inp);
		switch (user_inp) {
			case 1: {
				int x;
				printf("Enter the element to insert : ");
				scanf("%d", &x);
				push(st, x);
				printf("Sucessfully inserted\n");
				break;
			}
			case 2: {
				pop(st);
				printf("Sucessfully deleted\n");
				break;
			}
			case 3: {
				printf("element at top is : %d\n", top(st));
				break;
			}
				
		}
		
	}
	
}
