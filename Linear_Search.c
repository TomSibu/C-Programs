/**********************************************************************************************
 * File             :   Linear_Search.c
 * Program          :   Program to perform Linear Search on an array of numbers
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   12/11/2023
***********************************************************************************************/

#include <stdio.h>

void main()
{
	int n,i,item,flag=0,count=0;
	count=+2;
	printf("Enter no of entries : ");
	scanf("%d",&n);
	count++;
	int a[n];
	printf("Enter %d numbers : ",n);
	for (i=0;i<n;i++)
	{
		count++;
		scanf("%d",&a[i]);
		count++;
	}
	count++;
	printf("Array : ");
	for (i=0;i<n;i++)
	{
		count++;
		printf(" %d",a[i]);
	}
	count++;
	printf("\n");
	printf("Enter the no to be searched : ");
	scanf("%d",&item);
	count++;
	for (i=0;i<n;i++)
	{
		count++;
		if (a[i]==item)
		{
			count++;
			flag=1;
			count++;
			printf("Number %d found at position %d",item,i+1);
			break;
		}
	}
	count++;
	if (flag==0)
	{
		count++;
		printf("Element not found");
	}
	printf("\nTime Complexity : %d", count);
	printf("\nSpace Complexity : %d\n", 20+4*n);
}
