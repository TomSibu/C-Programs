/**********************************************************************************
 * File             :   Queue_Operations.c
 * Program          :   Program to perform queue operations
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   18/10/2023
***********************************************************************************/

#include <stdio.h>

int front=-1,rear=-1;
void enqueue(int[],int);
void dequeue(int[]);
void display(int[]);

int main() {
	int max,operation;
	printf("Enter the max size of queue : ");
	scanf("%d",&max);
	int queue[max];
	do {
		printf("Enter the operation to be performed :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice : ");
		scanf("%d",&operation);
		switch (operation) {
			case 1: {
				enqueue(queue,max);
				break;
			}
			case 2: {
				dequeue(queue);
				break;
			}
			case 3: {
				display(queue);
				break;
			}
			case 4: {
				printf("Exiting the program.\n");
				return 0;
			}
			default: {
				printf("Invalid operation : Try again\n");
				break;
			}
		}
	} while (operation!=4);
	return 0;
}

void enqueue(int queue[],int max) {
	int element;
	if (rear==max-1) {
		printf("Queue Overflow condition : Queue is full\n");
	}
	else {
		printf("Enter the element : ");
		scanf("%d",&element);
		rear++;
		queue[rear]=element;
		printf("Enqueued : %d\n",element);
	}
}


void dequeue(int queue[]) {
	int element;
	if (rear==-1 && front==-1) {
		printf("Queue Underflow condition : Queue is empty\n");
	}
	else if (rear<=front) {
		printf("Queue Underflow condition : Queue is empty\n");
	}
	else {
		front++;
		element=queue[front];
		printf("Dequeued : %d\n",element);
		if (rear<=front) {
			front=-1;
			rear=-1;
		}
	}
}

void display(int queue[]) {
	int i;
	printf("Queue : ");
	if (rear==-1 && front==-1) {
		printf("Empty");
	}
	for (i=front+1;i<rear+1;i++) {
		printf("%d ",queue[i]);
	}
	printf("\n");
}