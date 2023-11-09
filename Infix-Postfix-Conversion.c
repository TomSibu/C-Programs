/*********************************************************************************************************************
 * File             :   Infix-Postfix-Conversion.c
 * Program          :   Program to implement conversion of expression from one notation to another - Infix to Postfix
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   09/11/2023
**********************************************************************************************************************/

#include <stdio.h>
#include <string.h>

void insert(char[],char,char[]);
int gpres(char);

int j=0,top=-1;
char infix[100], stack[100], postfix[100];

void main() {
	int r=0;
	
	printf("Enter the Infix expression:");
	scanf("%s",infix);
	while (infix[r]!='\0'){
        	if((infix[r]>='a'&&infix[r]<='z')||(infix[r]>='A'&&infix[r]<='Z')) {
            		postfix[j]=infix[r];
            		j++;
        	}
        	else if(infix[r]=='+' || infix[r]=='-' || infix[r]=='*' || infix[r]=='/' || infix[r]=='^' || infix[r]=='(' || infix[r]==')') {
            		insert(stack , infix[r] , postfix);
            	}
        	else if(infix[r]==' ') {
            		continue;
            	}
		r++;
    	}
	
	while (top != -1) {
        	postfix[j] = stack[top];
        	j++;
        	top--;
    	}

	printf("Postfix expression: %s\n", postfix);
}

void insert(char stack[] , char k , char postfix[]) {
	if (top==-1) {
            	top=0;
            	stack[top]=k;
        }
        else if(k=='(') {
            	top++;
            	stack[top]=k;
        }
        else if(k==')') {
            	while (stack[top]!='(') {
                	postfix[j]=stack[top];
                	j++;
                	top--;
            	}
            	top--;
        }
        else if(k=='^') {
            	top++;
            	stack[top]=k;
        }
        else {
            	if (stack[top]!='(') {
                	int c=gpres(k) ,e=stack[top], d=gpres(e);

                	while (c<=d && top!=-1) {
                   		postfix[j]=stack[top];
                   		top--;
				j++;
                   		d=gpres(stack[top]);
                 	}
			
                	top++;
                	stack[top]=k;
            	}
            	else if(stack[top]=='(') {
               		top++;
               		stack[top]=k; 
            	}
        }
}

int gpres(char m){
    	if(m == '+')
       		return 1;
    	else if(m == '-')
		return 1;
    	else if(m == '*')
      		return 2;
    	else if(m == '/')
       		return 2;
    	else if(m == '^')
       		return 3;
    	else if (m == '(')
      		return -1;
}
