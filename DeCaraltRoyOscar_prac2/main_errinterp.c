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
    int eleccio;
    
    double *x, *f, *f2, res, equidist, u, j;
    
    FILE  *fitxer_sortida;    
    
    printf("Introdueix l'interval: \n");
    scanf("%le", &a);
    scanf("%le", &b);

    
    

    
        
    
    
    printf("Introdueix el grau del polinomi: \n");
    scanf("%d", &n);
        
    x = (double*)malloc((n+1)*sizeof(double));

    f = (double*)malloc((n+1)*sizeof(double));
    f2 = (double*)malloc((n+1)*sizeof(double));
    
    
    
    
    equidist = (b-a)/999;
    comptador = 0;
    
    printf("En quina funció vols avaluar, log (escriu 1) o runge (escriu qualsevol altre enter) ? \n");
    scanf("%d", &eleccio);
    
    if (eleccio == 1){
        fitxer_sortida = fopen("log.out", "w");
        if (fitxer_sortida == NULL){
            printf("No hi ha prou memòria\n");
            exit(1);
        }
        
        printf("Avaluant en log...\n");
        for (i = 0; i <= n+1; i++){
            x[comptador] = i;
            f[comptador] = fun_log(i);
            f2[comptador] = fun_log(i);
            comptador = comptador+1;
            
        }
    
    }
    else {
        fitxer_sortida = fopen("runge.out", "w");
        if (fitxer_sortida == NULL){
            printf("No hi ha prou memòria\n");
            exit(1);
        }
        printf("Avaluant en runge...\n");
        for (i = 0; i <= n+1; i++){
            x[comptador] = i;
            f[comptador] = fun_runge(i);
            f2[comptador] = fun_runge(i);
            comptador = comptador+1;
        }
    }

    res = difdiv(x, f, n);
    
    
    if (res == -1){
        printf("No s'ha trobat la solució...\n");
    }
    else{
        comptador = 0;
        printf("Printejant al fitxer...\n");
        for(j=a; j<=b; j += equidist){
            u = horner(j,x,f,n);
            fprintf(fitxer_sortida, "zj: %24.16e f(zj): %24.16e pn(zj): %24.16e\n", x[comptador], f2[comptador], u );
            comptador = comptador +1;

        }
            
    }
    printf("Comptador = %d  \n", comptador);
    fclose(fitxer_sortida);
    
    free(x);
    free(f);
    free(f2);


    
    return 0;
}
