/* Oscar de Caralt Roy */

#include<stdlib.h>
#include<stdio.h>
#include "funs_linalg.h"

#include <math.h>



int main(void){
    int n, i, j;
    double **A, **A2, *x,  *b, *b2, *y,*z, total = 0, tol, res;
    printf("Escriu la dimesió de la matriu quadrada : \n");
    scanf("%d", &n);
    A = (double **) malloc( n*sizeof(double *) );
    if (A == NULL){
        printf("No hay suficiente memoria");
        return 1;
    }
    for (i = 0; i < n; i++){
        A[i] = (double *) malloc( n*sizeof(double) );
        if ( A[i] == NULL){
            printf("No hay suficiente memoria");
            return 2;
        }
    }
    
    A2 = (double **) malloc( n*sizeof(double *) );
    if (A2 == NULL){
        printf("No hay suficiente memoria");
        return 1;
    }
    for (i = 0; i < n; i++){
        A2[i] = (double *) malloc( n*sizeof(double) );
        if ( A2[i] == NULL){
            printf("No hay suficiente memoria");
            return 2;
        }
    }
    
    x = (double *) malloc( n*sizeof(double) );
    z = (double *) malloc( n*sizeof(double) );
    b = (double *) malloc( n*sizeof(double) );
    b2 = (double *) malloc( n*sizeof(double) );
    y = (double *) malloc( n*sizeof(double) );
    if ( x == NULL || b == NULL || y == NULL ){
        printf("No hay suficiente memoria");
        return 3;
    }
    printf("Introdueix els elements (%d x %d) de la matriu A \n", n, n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &A[i][j]);
            printf("Element introduït = %.2e ", A[i][j]);
            A2[i][j] = A[i][j];
        }
    }
    
    
    printf("Introdueix els elements (%d) del vector b: \n", n);
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
        printf("Element introduït=%.2e \n", b[i]);
        b2[i]=b[i];
   
    
    }
    printf("Introdueix la tolerancia:");
    scanf("%lf", &tol);        
    res = gauss(n, A, b, tol);
    
    if (res==1){
           return 1;
        
    }else{
        /* Valor residual */
        printf("\n Valor residual ||Ax - b||^2 = \n");
        prodMatVec (n,n,A2,b,y);
        for (i=0; i <n; i++){
            z[i] = y[i] - b2[i];
        
        }
        total = prod_esc(n, z, z);
       
        total = sqrt(total);
        printf( "%24.16e", total);
        
        
        printf("\n Vector solució x : \n");
        for (i=0;i<n;i++){
            printf( "%24.16e", b[i]);
        }
    }
  
        
    
		
    
    
    
    printf("\n");
    
    for (i = 0; i < n; i++)
        free (A[i]);
    for (i = 0; i < n; i++)
        free (A2[i]);
    free(A2);
    free(A);
    
    
    free(x);
    free(b);
    free(b2);
    free(y);
    return 0;
}


