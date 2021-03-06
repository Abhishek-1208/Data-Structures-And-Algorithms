/**
 * program to implement our own queue
 * compilation: gcc queue.c
 * Execution: Data-Structures-And-Algorithms/coding/queue.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 6
*/

#include <stdio.h>
#include<stdlib.h>


//structure to represent our stack
struct queue {
	int front, last, curr_size, capacity, *arr;
	
};

//to initialize our queue with some predefined size
struct queue* init() {
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	q -> arr = (int *)malloc(5 * sizeof(int));
	q -> capacity = 5;
	q -> front = -1;
	q -> last = -1;
	q -> curr_size = 0;
}

// to resize our queue incase maximum capacity has been reached

void resize(struct queue *q) {
	
	q = realloc(q, q -> capacity * 2);
	
	//adjustment of element is only needed if last element is present before the first element
	if(q -> front > q -> last) {
		//copying the content of the queue to temporary array first

		int *temp = (int *)malloc(q -> capacity * sizeof(int));
		int index = 0,start = q -> front;
		while(start < q -> capacity) {
			temp[index++] = q -> arr[start++];
		}

		start = 0;
		while(start <= q -> last) {
			temp[index++] = q -> arr[start++];
		}

		//copying back the data
		start = 0;
		while(start < q -> capacity) {
			q -> arr[start] = temp[start++];
		}
			
			
	}
	
	q -> front = 0;
	q -> last = q -> capacity - 1;
	q -> capacity *= 2;
	
}
//to check if the queue is empty or not
int empty(struct queue *q) {
	return q -> curr_size == 0;
}
//to check if the queue is full or not
int full(struct queue *q) {
	return q -> curr_size == q -> capacity;
}
//to get current size of queue
int size(struct queue *q) {
	return q -> curr_size;
}

//to push the element at the end of queue
void push(struct queue *q,int x) {
	//resize if max capacity has been reached
	if(full(q)) {
		resize(q);
	}	

	q -> last = (q -> last + 1) % q -> capacity;
	q -> arr[q -> last] = x;
	q -> curr_size++;
	
	if(q -> curr_size == 1) {
		q -> front = q -> last;
	}
	
}
//to pop the element at front of queue if present
void pop(struct queue *q) {
	//first check if queue is empty or not
	if(empty(q)) {
		printf("queue underflow\n");
		exit(1);
	}
	
	else {
		q -> front = (q -> front + 1) % q -> capacity;
		q -> curr_size--;
	}
	
}
//to get the element at front of queue
int front(struct queue *q) {
	//first check if queue is empty or not
	if(empty(q)) {
		printf("Error!..queue is empty\n");
		exit(1);
	}
	
	else {
		return q -> arr[q -> front];
	}
	
}
// to get the  element at back of queue
int back(struct queue *q) {
	
	//first check if queue is empty or not
	if(empty(q)) {
		printf("Error!..queue is empty\n");
		exit(1);
	}
	
	else {
		return q -> arr[q -> last];
	}
	
}



int main() {
	
    	struct queue *q;
	q = init();	
	
	//interface to play with our queue data structure
	
	int n;
	printf("Enter the number of operations: ");
	scanf("%d", &n);
	
	while(n--) {
		printf("press 1 to insert\n");
		printf("press 2 to delete\n");
		printf("press 3 to get front element\n");
		printf("press 4 to get back element\n");
		printf("enter your choice: ");
		int user_inp;
		scanf("%d", &user_inp);
		switch (user_inp) {
			case 1: {
				int x;
				printf("Enter the element to insert : ");
				scanf("%d", &x);
				push(q, x);
				printf("Sucessfully inserted\n");
				break;
			}
			case 2: {
				pop(q);
				printf("Sucessfully deleted\n");
				break;
			}
			case 3: {
				printf("element at front is : %d\n", front(q));
				break;
			}
			case 4: {
				printf("element at back is %d\n", back(q));
				break;
			}
				
		}
		
	}
}
