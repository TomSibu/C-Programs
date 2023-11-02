/**********************************************************************************
 * File             :   Circular_Queue.c
 * Program          :   Program to implement Circular Queue
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   02/11/2023
***********************************************************************************/

#include <stdio.h>

int front=-1,rear=-1;
void enqueue(int[],int);
void dequeue(int[],int);
void display(int[],int);

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
				dequeue(queue,max);
				break;
			}
			case 3: {
				display(queue,max);
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
	if (front==(rear+1)%max) {
		printf("Queue Overflow condition : Queue is full\n");
	}
	else if(rear==-1 && front==-1) {
		printf("Enter the element : ");
		scanf("%d",&element);	
        	rear=0,front=0;
        	queue[rear]=element;
        	printf("Enqueued : %d\n",element);
    	}
	else {
		printf("Enter the element : ");
		scanf("%d",&element);
		rear=(rear+1)%max;
		queue[rear]=element;
		printf("Enqueued : %d\n",element);
	}
}


void dequeue(int queue[],int max) {
	int element;
	if (rear==-1 && front==-1) {
		printf("Queue Underflow condition : Queue is empty\n");
	}
	else if(front==rear) {
		element=queue[front];
       		printf("Dequeued : %d\n",element);
       		front=-1,rear=-1;
    	}	
	else {
		element=queue[front];
		front=(front+1)%max;
		printf("Dequeued : %d\n",element);
	}
}

void display(int queue[],int max) {
	printf("Queue : ");
	if (rear==-1 && front==-1) {
		printf("Empty");
	}
	else {
          	int i=front;
         	while(i!=rear) {
          		printf("%d ",queue[i]);
          		i=(i+1)%max;
   		}
       		printf("%d",queue[i]);
	}
	printf("\n");
}
