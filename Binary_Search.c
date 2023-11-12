/**********************************************************************************************
 * File             :   Binary_Search.c
 * Program          :   Program to perform Binary Search on an array of numbers
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   12/11/2023
***********************************************************************************************/

#include <stdio.h>

void main() {

	int i,j,n, flag=0,element,count=0;
	count++;
	count++;
	printf("Enter no of entries : ");
	scanf("%d",&n);
	count++;
	int arr[n];
	printf("Enter %d numbers : ",n);
	for (i=0;i<n;i++) {
		count++;
		scanf("%d",&arr[i]);
		count++;
	}
	count++;
	printf("Array :");
	for (i=0;i<n;i++) {
		count++;
		printf(" %d",arr[i]);
	}
	count++;
	printf("\n");
	
	printf("Sorted Array : ");
	for (i=0;i<n-1;i++) {
		count++;
		for (j=i+1;j<n;j++) {
			count++;
			if (arr[i]>arr[j]) {
				count++;
				int temp=arr[i];
				count++;
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		count++;
	}
	count++;
	for (i=0;i<n;i++) {
		count++;
		printf(" %d",arr[i]);
	}
	count++;
	printf("\n");
	
	printf("Enter the number to be searched : ");
	scanf("%d",&element);
	count++;
	
	int left=0, right = n-1, middle;
	count++;
	count++;
	
	
	while (left<=right) {
		count++;
		middle = (left + right)/2;
		if (element == arr[middle]) {
			count++;
			printf("Number %d found at position %d\n", element, middle+1);
			flag = 1;
			count++;
			break;
		}
		else if (element > arr[middle]) {
			count++;
			left = middle+1;
			count++;
		}
		else {
			count++;
			right = middle-1;
		}
	}
	count++;
	if (flag==0) {
		count++;
		printf("Number %d not found\n",element);
	}
	printf("Time Complexity : %d\n",count);
	printf("Space Complexity : %d\n", 40+4*n);
}
