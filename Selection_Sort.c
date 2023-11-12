/**********************************************************************************************
 * File             :   Selection_Sort.c
 * Program          :   Program to implement Selection Sort on an array of numbers
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
    		count++;
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
    	//Selection Sort
    	for (i=0;i<n-1;i++) {
    		count++;
    		small=i;
    		count++;
    		for (j=i+1;j<n;j++) {
        		count++;
        		if (arr[small]>arr[j]) {
            			count++;
            			small=j;
            			count++;
        			}
    		}
    		count++;
    		if (small!=i) {
        		count++;
        		temp=arr[i];
        		arr[i]=arr[small];
        		arr[small]=temp;
        		count+=3;
    		}
    	}
    	count++;
    	printf("Sorted Array using Selection Sort :");
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
