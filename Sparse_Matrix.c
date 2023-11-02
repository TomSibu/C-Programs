/**********************************************************************************
 * File             :   Sparse_Matrix.c
 * Program          :   Program to represent sparse matrix using array
 * Language         :   C
 * Author           :   Tom Sibu
 * Version          :   1.0
 * Date             :   02/11/2023
***********************************************************************************/

#include <stdio.h>

int main() {
    	int n=1,i,j,rows,columns,nonzero=0;
    	printf("Enter the rows and columns of sparse matrix : ");
    	scanf("%d%d",&rows,&columns);
    	int sparse[rows][columns];
    	printf("Enter the elements in sparse matrix :\n");
    	for (i=0;i<rows;i++) {
        	for (j=0;j<columns;j++) {
            		scanf("%d",&sparse[i][j]);
            		if (sparse[i][j]!=0) {
                		nonzero++;
            		}
        	}
    	}
    	printf("Sparse Matrix\n");
    	for (i=0;i<rows;i++) {
        	for (j=0;j<columns;j++) {
            		printf(" %d",sparse[i][j]);
        	}
       		printf("\n");
    	}
    	int new[nonzero+1][3];
    	new[0][0]=rows;
    	new[0][1]=columns;
    	new[0][2]=nonzero;
    	for (i=0;i<rows;i++) {
        	for (j=0;j<columns;j++) {
            		if (sparse[i][j]!=0) {
                		new[n][0]=i;
                		new[n][1]=j;
                		new[n][2]=sparse[i][j];
                		n++;
            		}
        	}
    	}
    	printf("Sparse Matrix Representation\n");
    	for (i=0;i<nonzero+1;i++) {
    		for (j=0;j<3;j++) {
            		printf(" %d",new[i][j]);
        	}
        	printf("\n");
    	}
}
