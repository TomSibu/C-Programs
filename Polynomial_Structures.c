/**********************************************************************************
 * File             :   Polynomial_Structures.c
 * Program          :   Program to represent polynomial using structures
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   02/11/2023
***********************************************************************************/

#include <stdio.h>

struct polynomial {
    	int coeff;
    	int degree;
}p;

void main() {
    	int polyterms,i;
    	printf("Enter the no of polynomial terms : ");
    	scanf("%d",&polyterms);
    	struct polynomial p[polyterms];
    	printf("Enter the coefficients and degree of the terms\n");
    	for (i=0;i<polyterms;i++) {
        	printf("Enter the coeffient of term %d : ",i+1);
        	scanf("%d",&p[i].coeff);
        	printf("Enter the degree of term %d : ",i+1);
        	scanf("%d",&p[i].degree);
    	}
    	printf("Polynomial: ");
    	for (i=0;i<polyterms;i++) {
        	printf("%dx^%d",p[i].coeff,p[i].degree);
        	if (i < polyterms - 1) {
            		printf(" + ");
        	}
    	}
    	printf("\n");
}
