/*******************************************************************************************
 * File	            :	Queue_Operations.c
 * Description      :   Program to perform Queue operations (Enqueue/Dequeue) using array
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   15/10/2023
********************************************************************************************/

#include <stdio.h>

// Declaring the functions
void enqueue(int,int*,int*,int[]);
void dequeue(int,int*,int*,int[]);
void display(int,int,int,int[]);

// main function
int main() {
    int n, operation, choice;

    printf("Enter the no of entries in queue : ");                   // Reading the queue size
    scanf("%d",&n);

    int queue[n];
    int size = 0, rear = -1, front = 0;                              // Initializing the variables
    
    do {
        printf("What operation do you want to perform ?\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        scanf("%d",&operation);

        switch(operation) {

            case 1: {                                                // Enqueue : Inserting a number to the rear
                enqueue(n,&size,&rear,queue);
                break;
            }

            case 2: {                                                // Dequeue : Deleting a number from the front
                dequeue(n, &size, &rear, queue);
                break;
            }

            case 3: {                                                // Display : Displaying the queue
                display(n, size, front, queue);
                break;
            }

            case 4: {                                                // Exit : To end the program
                printf("Exiting the program.\n");
                return 0;
            }

            default: {                                               // Invalid operation
                printf("Invalid Operation\n");
                break;
            }

        }
    } while (operation != 4);                                        // The program runs until the user enters (4. Exit) as choice
    
    return 0;
}

// Function for enqueue
void enqueue(int n,int *size,int *rear,int queue[]) {
    int num;
    if (*size == n) {                                                // Checking for Overflow condition
        printf("Overflow. Queue is full.\n");
    }
    else {
        printf("Enter number : ");
        scanf("%d", &num);
        *rear = (*rear + 1) % n;                                     // else array index will go beyond its bounds
        (*size)++;
        queue[*rear] = num;
        printf("Enqueued: %d\n",num);
    }
}

// Funtion for dequeue
void dequeue(int n,int *size, int *front, int queue[]) {
    if (*size == 0) {                                                // Checking for Underflow condition
        printf("Underflow. Queue is empty.\n");
    }
    else {
        printf("Dequeued: %d\n", queue[*front]);
        *front = (*front + 1)%n;                                     // else array index will go beyond its bounds
        (*size)--;
    }
}

// Function for display
void display(int n, int size, int front, int queue[]) {
    if (size == 0) {                                                 // Checking if queue is empty
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements : ");
        for (int i=0; i < size; i++) {
            int index = (front + i) % n;
            printf("%d ", queue[index]);                             // Printing queue elements
        }
        printf("\n");
    }
}