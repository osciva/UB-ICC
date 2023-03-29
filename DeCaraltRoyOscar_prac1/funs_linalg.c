/* Oscar de Caralt Roy */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funs_linalg.h"


int resoltrisup(int n, double** A, double* b, double *x, double tol) {
    
    int cont1, cont2;
    
    
    
    if (fabs(A[n-1][n-1]) >= tol) {
        x[n-1]= b[n-1]/(A[n-1][n-1]);
       
    }
    
    else{
        return 1;
    }
    
    for (cont1 = n-2; cont1 >= 0; cont1--) {
        x[cont1] = b[cont1];
        
        if (fabs(A[cont1][cont1]) >= tol) {
            
            for (cont2 = cont1+1; cont2 <= n-1; cont2++) {
                x[cont1] -= (A[cont1][cont2] * x[cont2]);
            }
            
            x[cont1] /= A[cont1][cont1];

            
        }
        
        else {
            return 1;
        }
        
    }
    printf("\n");
    
    return 0;
    
}
    

void resoltriinf(int n, double **L, double *x, double *b){
    int i,j;
    
    for (i=1; i<=n; i++){
        x[i] = b[i];
        for(j= 1; j<=i-1; j++){
            x[i] -= x[j] * L[i][j];
        }
    }
}

void prodMatVec (int m, int n, double **A, double *x, double *y){
    int i,j;
    
    for (i = 0; i < m; i++){
        y[i] = 0;
        for (j = 0; j < n; j++){
            y[i] += x[j] * A[i][j];
        }
    }
}

double prod_esc (int dim, double* x, double* y){
    double prod = 0;
    int i;
    
    for (i = 0; i < dim; i++){
        prod += x[i]* y[i];
    }
    
    return prod;
}



int gauss(int n, double **A, double *b, double tol) {
    
    double *t;
    double temp;
    int cont1, cont2, cont3, i,/* j,*/ a;

    
    t = (double *) malloc (n * sizeof(double));
    
    for (cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = b[cont1];
    }
    
    for (cont2 = 0; cont2 < n-1; cont2++) {
        for (i = cont2 + 1; i < n; i++) {
            
            if (fabs(A[cont2][cont2]) >= tol) {
                temp = A[i][cont2] / A[cont2][cont2];
                
                for (cont3 = cont2; cont3 < n; cont3++) {
                    A[i][cont3] -= A[cont2][cont3] * temp;
                    
                }
                
            }
            
            else {
                return 1;
            }
            
            t[i] -= t[cont2] * temp;
            
        }
    }
    
    a = resoltrisup(n, A, t, b, tol);

    free(t);
    
/*  for (i = 0; i < n; i++){
        
        for (j = 0; j < n; j++){
            printf("%24.16e " , A[i][j]);        
            
        }
        
    }*/
    
    return a;
    
    
}


int gausspiv(int n, double **A, double *v,  double tol) {
    
    int   i,j,k,m,rowx;
    double *x,xfac,temp,temp1,amax;
    x = (double *) malloc (n * sizeof(double));
    
    
    rowx = 0;   /* Comptador d'intercanvis */
    for (k=0; k<=n-1; k++) { /* k=1 orig k=0 subst*/
        amax = A[k][k]; /*amax = (double) fabs(A[k][k]) ;*/
        m = k;
        for (i=k+1; i<=n; i++){   /* busquem la fila amb major valor a l'index 'i'    ---> error també amb i<=n orig i < n subst*/
            
            if (fabs(A[k][k]) >= tol){ /* ---> error també amb fabs(A[i][i]) >= tol orig */
                xfac = A[i][k]/A[k][k]; /* ---> error també amb xfac = (double) fabs(A[i][k]);*/
                if(xfac > amax) {
                    amax = xfac;
                    m=i;
                    
                }
                if(m != k) {  /* Intercanvi de files */
                    rowx = rowx+1;
                    temp1 = v[k];
                    v[k]  = v[m];
                    v[m]  = temp1;
                    for (j=k; j<n; j++) { /* ---> error també amb j=k+1; j<=n; ++j orig */
                        temp = A[k][j];
                        A[k][j] = A[m][j];
                        A[m][j] = temp;
                        A[i][j] = A[i][j]-xfac*A[k][j];
                        /*printf("%24.16e " , A[i][j]);*/
                    }
                }
            }
            
            else {
                return 1;
            }
            v[i] = v[i]-xfac*v[k];
        }
                
                
    }


    resoltrisup(n, A, v, x, tol);
    
    
    free(v);
    return 0;
    
}

double generateACP(int n, double **A, double *b, double tol){
    double *t;
    double temp;
    int cont1, cont2, cont3, i;/* j,*/

    
    t = (double *) malloc (n * sizeof(double));
    
    for (cont1 = 0; cont1 < n; cont1++) {
        t[cont1] = b[cont1];
    }
    
    for (cont2 = 0; cont2 < n-1; cont2++) {
        for (i = cont2 + 1; i < n; i++) {
            
            if (fabs(A[cont2][cont2]) >= tol) {
                temp = A[i][cont2] / A[cont2][cont2];
                
                for (cont3 = cont2; cont3 < n; cont3++) {
                    A[i][cont3] -= A[cont2][cont3] * temp;
                    
                }
                
            }
            
            else {
                return 1;
            }
            A[i][cont2] = temp;
            t[i] -= t[cont2] * temp;
            
            
        }
    }
    
    

    free(t);
    return **A;
}


double checkLU(int n, double **a, double **acp){
    int i, j, k, aux;
    double top = 0;
    
    for(i = 0; i <= n; i++){
        for(j = i; j <= n; j++){
            aux = 0;
            for(k = 0; k <= n; k++){
                aux += acp[i][k]*acp[k][j];
            }
            a[i][j] -= aux;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[i][j] >= top){
                top = a[i][j];
            }
        }
    }
    return (top);
}
