/**********************************************************************************
* Experiment No	:	9
* Aim           :	Program to implement Polynomial Addition using Linked List
* Name          :	Tom Sibu
* Class         :	S3 CSE B
* Roll No       :	63
* System No     :	31
* Date          :	30/11/2023
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int coeff;
	int exp;
	struct node* next;
};

struct node* createNode(int coeff, int exp) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL;
	return newNode;
}

void insertTerm(struct node** poly, int coeff, int exp) {
    struct node* newNode = createNode(coeff,exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
    
    	if (poly1->exp>poly2->exp && poly1 != NULL) {
    		insertTerm(&result, poly1->coeff, poly1->exp);
    		if (poly1 != NULL) poly1 = poly1->next;
    	}
    	else if (poly2->exp>poly1->exp && poly2 != NULL) {
    		insertTerm(&result, poly2->coeff, poly2->exp);
    		if (poly2 != NULL) poly2 = poly2->next;
    	}
    	else {
    		int coef1 = (poly1 != NULL) ? poly1->coeff : 0;
        	int exp1 = (poly1 != NULL) ? poly1->exp : 0;
        	int coef2 = (poly2 != NULL) ? poly2->coeff : 0;
        	int exp2 = (poly2 != NULL) ? poly2->exp : 0;

        	int sumCoeff = coef1 + coef2;
        	int sumExp = exp1;
	
        	insertTerm(&result, sumCoeff, sumExp);
        	
        	if (poly1 != NULL) poly1 = poly1->next;
        	if (poly2 != NULL) poly2 = poly2->next;
    	}
    }
    return result;
}

void displayPolynomial(struct node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void main() {
	int n,coeff,exp,d;
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    printf("******** Polynomial 1 ********\n");
    printf("Enter no of terms: ");
    scanf("%d",&n);
    d=n;
    while (n!=0) {
    	printf("Enter coefficient of term %d: ",(d%n)+1);
    	scanf("%d",&coeff);
    	printf("Enter exponent value: ");
    	scanf("%d",&exp);
    	insertTerm(&poly1,coeff,exp);
    	n--;
    }
    
    printf("\n******** Polynomial 2 ********\n");
	printf("Enter no of terms: ");
    scanf("%d",&n);
    d=n;
    while (n!=0) {
    	printf("Enter coefficient of term %d: ",(d%n)+1);
    	scanf("%d",&coeff);
    	printf("Enter exponent value: ");
    	scanf("%d",&exp);
    	insertTerm(&poly2,coeff,exp);
    	n--;
    }
	
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

}
