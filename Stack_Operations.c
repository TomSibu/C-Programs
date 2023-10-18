/**********************************************************************************
 * File             :   Stack_Operations.c
 * Program          :   Program to perform stack operations
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   18/10/2023
***********************************************************************************/

#include <stdio.h>

int top=-1;
void push(int[],int);
void pop(int[]);
void display(int[]);
void peek(int[]);

int main() {
	int max,operation;
	printf("Enter the max size of stack : ");
	scanf("%d",&max);
	int stack[max];
	do {
		printf("Enter the operation to be performed :\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nChoice : ");
		scanf("%d",&operation);
		switch (operation) {
			case 1: {
				push(stack,max);
				break;
			}
			case 2: {
				pop(stack);
				break;
			}
			case 3: {
				display(stack);
				break;
			}
			case 4: {
				peek(stack);
				break;
			}
			case 5: {
				printf("Exiting the program.\n");
				return 0;
			}
			default: {
				printf("Invalid operation : Try again\n");
				break;
			}
		}
	} while (operation!=5);
	return 0;
}

void push(int stack[],int max) {
	int element;
	if (top==max-1) {
		printf("Stack Overflow condition : Stack is full\n");
	}
	else {
		printf("Enter the element : ");
		scanf("%d",&element);
		top++;
		stack[top]=element;
		printf("Pushed : %d\n",element);
	}
}


void pop(int stack[]) {
	int element;
	if (top==-1) {
		printf("Stack Underflow condition : Stack is empty\n");
	}
	else {
		element=stack[top];
		top--;
		printf("Popped : %d\n",element);
	}
}

void display(int stack[]) {
	int i;
	printf("Stack : ");
	if (top==-1) {
		printf("Empty");
	}
	for (i=top;i>=0;i--) {
		printf("%d ",stack[i]);
	}
	printf("\n");
}

void peek(int stack []) {
	if (top==-1) {
		printf("Stack is Empty");
	}
	else {
		printf("Topmost element : %d\n",stack[top]);
	}
}