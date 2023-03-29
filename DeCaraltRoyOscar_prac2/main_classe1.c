/* Oscar de Caralt Roy */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "funs_interp.h"



int main(void){
    
    int n;
    double a;
    double b;
    int i;
    int comptador;
    
    double *x, *f, res, equidist, u, j;
    
    FILE *fitxer, *fitxer_sortida;    
    
    printf("Introdueix l'interval: \n");
    scanf("%le", &a);
    scanf("%le", &b);

    
    

    
    fitxer = fopen("taula.in", "r");
    
    fitxer_sortida = fopen("p3taula.out", "w");
    
    if (fitxer == NULL || fitxer_sortida == NULL){
        printf("No hi ha prou memòria\n");
        exit(1);
    }
    
       

    
    printf("Introdueix el grau del polinomi: \n");
    fscanf(fitxer, "%d", &n);   

        
    x = (double*)malloc((n+1)*sizeof(double));

    f = (double*)malloc((n+1)*sizeof(double));
    
    
    
    
    
    for (i = 0; i < n+1; i++){
        printf("Introduir l'element %d del vector x:\n", i+1);
        fscanf(fitxer,"%le", &x[i]);
        
    }
    
    for (i = 0; i < n+1; i++){
        printf("Introduir l'element %d del vector f(x):\n", i+1);
        fscanf(fitxer, "%le", &f[i]);
    }
    

    
    
    

    

    
    res = difdiv(x, f, n);
    equidist = (b-a)/999;
    
    if (res == -1){
        printf("No s'ha trobat la solució...\n");
    }
    else{
        comptador = 0;
        for(j=a; j<=b; j += equidist){
            u = horner(j,x,f,n);
            fprintf(fitxer_sortida, "%24.16e %24.16e\n", j, u );
            comptador = comptador +1;

        }
            
    }
    printf("Comptador = %d  \n", comptador);
    fclose(fitxer_sortida);
    
    free(x);
    free(f);


    
    return 0;
}
