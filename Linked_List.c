/*********************************************************************************************************************
 * File             :   Linked_List.c
 * Program          :   Program to implement of Linked List operations
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   16/11/2023
**********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void Insertion();
void Deletion();
void Display();
void insertbegin(int);
void insertend(int);
void insertany(int);
void deletebegin();
void deleteend();
void deleteany();

struct node {
	int data;
    	struct node *next;
} *head;

void main() {
    	int choice;
    	do {
        	printf("\nChoose an operation to perform\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) {
        		case 1:
            			Insertion();
            			break;
        		case 2:
            			Deletion();
            			break;
        		case 3:
            			Display();
            			break;
        		case 4:
            			printf("Exiting the program.\n");
            			break;
        		default:
            			printf("Invalid Choice.\n");
            			break;
        	}
    	} while (choice != 4);
}

void Insertion() {
    	int choice, item;
    	printf("\nInsertion\n1.At beginning\n2.At End\n3.At any location\n4.Return\n");
    	do {
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	if (choice==4) {
        		printf("Returning to menu.\n");
            		break;
        	}
        	printf("Enter value: ");
        	scanf("%d", &item);
        	switch (choice) {
        		case 1:
            			insertbegin(item);
            			break;
        		case 2:
            			insertend(item);
            			break;
        		case 3:
           	 		insertany(item);
            			break;  
        		default:
            			printf("Invalid Choice.\n");
            			break;
        	}
    	} while (choice != 4);
}

void Deletion() {
    	int choice;
    	printf("\nDeletion\n1.From beginning\n2.From End\n3.From any location\n4.Return\n");
    	do {
    	    	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) {
        		case 1:
            			deletebegin();
            			break;
        		case 2:
            			deleteend();
            			break;
        		case 3:
            			deleteany();
            			break;
        		case 4:
            			printf("Returning to menu.\n");
            			break;
        		default:
            			printf("Invalid Choice.\n");
            			break;
        }
    	} while (choice != 4);
}

void Display() {
    	struct node *ptr;
    	ptr = head;
    	if (ptr == NULL)
    	    	printf("List Empty\n");
    	else {
        	printf("\nThe Elements are:");
        	while (ptr != NULL) {
        	    	printf(" %d", ptr->data);
            		ptr = ptr->next;
        	}
        	printf("\n");
    	}
}

void insertbegin(int item) {
    	struct node *ptr;
    	ptr = (struct node *)malloc(sizeof(struct node));
    	ptr->data = item;
    	ptr->next = head;
    	head = ptr;
    	printf("Element %d inserted at beginning\n",item);
}

void insertend(int item) {
    	struct node *ptr, *temp;
    	ptr = (struct node *)malloc(sizeof(struct node));
    	ptr->data = item;
    	if (head == NULL) {
        	ptr->next = NULL;
        	head = ptr;
        	printf("Element %d inserted at end\n",item);
    	} else {
        	temp = head;
        	while (temp->next != NULL)
        	    	temp = temp->next;
        		temp->next = ptr;
        	ptr->next = NULL;
        	printf("Element %d inserted at end\n",item);
    	}
}

void insertany(int item) {
    	int i, loc;
    	struct node *ptr, *temp;
    	ptr = (struct node *)malloc(sizeof(struct node));
    	ptr->data = item;
    	printf("Enter the position at which you want to insert: ");
    	scanf("%d", &loc);
    	loc--;
    	temp = head;
    	for (i = 0; i < loc; i++) {
        	temp = temp->next;
        	if (temp == NULL) {
            		printf("Can't insert\n");
            		break;
        	}
    	}
    	ptr->next = temp->next;
    	temp->next = ptr;
    	printf("Element %d inserted at position %d\n",item,loc);
}

void deletebegin() {
    	struct node *ptr;
    	ptr = head;
    	if (head == NULL)
        	printf("List is empty\n");
    	else {
        	head = ptr->next;
        	printf("Element %d deleted from the beginning\n",ptr->data);
        	free(ptr);
    	}
}

void deleteend() {
    	struct node *ptr, *ptr1;
    	if (head == NULL)
        	printf("List is empty\n");
    	else if (head->next == NULL) {
        	head = NULL;
        	free(head);
        	printf("Only node of the list deleted\n");
    	} else {
        	ptr = head;
        	while (ptr->next != NULL) {
            		ptr1 = ptr;
            		ptr = ptr->next;
        	}
        	ptr1->next = NULL;
        	printf("Element %d deleted from the end\n",ptr->data);
        	free(ptr);
    	}
}

void deleteany() {
    	struct node *temp = head;
    	int i, pos;
    	printf("Enter the position of the node you want to perform deletion: ");
    	scanf("%d", &pos);
    	if (pos == 1) {
    	    	printf("Element deleted is : %d\n", temp->data);
        	head = head->next;
        	temp->next = NULL;
        	free(temp);
    	} else {
        	for (i = 0; i < pos - 1; i++)
            		temp = temp->next;
        	struct node *del = temp->next;
        	temp->next = temp->next->next;
        	printf("Element deleted is : %d\n", del->data);
        	del->next = NULL;
        	free(del);
    	}
}
