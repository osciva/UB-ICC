/* Oscar de Caralt Roy */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "funs_linalg.h"



void transposar_matriu(int n, double** L);

int main(){
    int n, i, j;
    double **L, **L2, *b, *x, *y, sum, res, norma, tol;

    printf("Introdueix la dimensio de la matriu: ");
    scanf("%d", &n);

    
    /*Inicialitzem matriu L i vectors b, x i y */
    
    x = (double*)malloc(n*sizeof(double));
    y = (double*)malloc(n*sizeof(double));
    
    L = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        L[i]= (double*)malloc(n*sizeof(double));
    }
    L2 = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        L2[i]= (double*)malloc(n*sizeof(double));
    }
    
    
    /* Llegim la matriu i comprovem que sigui triangular superior */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &L[i][j]);
            printf("Element introduït = %.2e \n", L[i][j]);
            L2[i][j] = L[i][j];
        }
        
    }
    
    b = (double*)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
        printf("Element introduït=%.2e \n", b[i]);
    }
    printf("Introdueix la tolerancia:");
    scanf("%lf", &tol);

    res = resoltrisup(n, L, b, x, tol);
    
    if (res == 1){
        return 1;
    }
    else{
        
        prodMatVec(n, n, L, x, y);
        
        sum = prod_esc(n, x, y);
        norma = sqrt(sum);
    
        /*Imprimim el vector solucio i la norma |Lx-b|2*/
        printf("\nEl vector solucio es:\n");
        for(i = 0; i < n; i++){
            printf("%24.16e", x[i]);
        }
        printf("\n");
        
        printf("\nLa norma |Lx - b|2 es: %f\n", norma);
    }
    /* Transposem la matriu L i calculem la solució del sistema triangular inferior resultant
     */
 /* transposar_matriu(n, L2); */
    
/*  resoltriinf(n, L2, x, b); */
    
    /*Imprimim el vector solucio del sistema triangular inferior*/
 /* printf("\nEl vector solucio del sistema triangular inferior es:\n");
    for(i = 0; i < n; i++){
        printf("%25.16e", x[i]);
    }
    printf("\n");
    
*/    
    /*Alliberar matrius*/
    for(i = 0; i < n; i++){
        free(L[i]);
    }
    for(i = 0; i < n; i++){
        free(L2[i]);
    }
    free(L);
    free(L2);
    free(b);
    free(x);
    free(y);

    
    return 0;
}

/*Aquesta funcio transposa una matriu quadrada de dimensio n*/
void transposar_matriu(int n, double** A){
    double aux;
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j < n; j++){
            if(i > j){
                aux = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = aux;
            }
        }
    }
}
