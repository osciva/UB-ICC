/* Oscar de Caralt Roy */

#include <stdio.h>
#include <stdlib.h>
#include "funs_interp.h"
#include <math.h>

double horner(double z, double *x, double *c, int n){
     
    int i;
    double p = c[n];

    for(i = n-1; i>=0; i--){
        p = p *(z-x[i]) + c[i];
    }
    return p;

}


int difdiv(double *x, double *f, int n){

    int i;
    int k;
    double tol = 1.e-12;
    
    for(k=1; k<=n; k++){
        for(i = n; i >=k; i--){
            if(fabs(x[i]-x[i-k]) <= tol){
                return -1;
            }
            
            f[i] = (f[i]-f[i-1])/(x[i]-x[i-k]);
            
        }
    }



    return 0;




}

double fun_log(double z){
    return log(z);
}

double fun_runge(double z){
    return 1/(1+25*z*z);
}

