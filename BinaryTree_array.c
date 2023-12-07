/**********************************************************************************
 * File             :   BinaryTree_array.c
 * Program          :   Implementation of binary trees using arrays
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   07/12/2023
***********************************************************************************/

#include <stdio.h>

void insert(int tree[], int data, int position) {
    tree[position] = data;
}

void inOrderTraversal(int tree[], int position, int n) {
    if (position < n && tree[position] != -1) {
        inOrderTraversal(tree, 2 * position + 1, n);
        printf("%d ", tree[position]);
        inOrderTraversal(tree, 2 * position + 2, n);
    }
}


void main() {
	int n, num;

    printf("Enter max size of tree: ");
    scanf("%d", &n);
    
    int tree[n];
    
    for (int i = 0; i < n; i++) {
    	tree[i] = -1;
        printf("Enter the number to position %d: ", i);
        scanf("%d", &num);
        insert(tree, num, i);
    }
    
    printf("In-order traversal: ");
    inOrderTraversal(tree, 0, n);
    printf("\n");
}
