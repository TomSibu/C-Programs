/**********************************************************************************************
 * File             :   Bubble_Sort.c
 * Program          :   Program to implement Bubble Sort on an array of numbers
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   12/11/2023
***********************************************************************************************/

#include <stdio.h>
void main() {
int n,i,j,small=0,temp=0,count=0;
    	count+=3;
    	printf("Enter the number of entries : ");
    	scanf("%d",&n);
    	int arr[n];
    	printf("Enter %d numbers : \n",n);
    	count++;
    	for (i=0;i<n;i++) {
    		count++;
    		scanf("%d",&arr[i]);
    		Count++;
	}
    	count++;
    	printf("Unsorted Array :");
    	for (i=0;i<n;i++) {
    		count++;
    		printf(" %d",arr[i]);
    		count++;
	}
    	count++;
    	printf("\n");
    	//Bubble Sort
    	for (i=0;i<n-1;i++) {
    		count++;
   	 	for (j=i+1;j<n;j++) {
   	 		count++;
   		 	if (arr[i]>arr[j]) {
   		 		count++;
   			 	temp=arr[i];
   			 	arr[i]=arr[j];
   			 	arr[j]=temp;
   			 	count+=3;
			}
   	 	}
		count++;
    	}
	count++;
    	printf("Sorted Array using Bubble Sort :");
    	for (i=0;i<n;i++) {
    		count++;
    		printf(" %d",arr[i]);
    		count++;
	}
    	count++;
    	printf("\n");
    	//Time Complexity & Space Complexity
    	count+=2;
    	printf("Time Complexity of program : %d\n",count);
    	printf("Space Complexity of program : %d\n",24+4*n);
}
