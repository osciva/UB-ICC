/* Oscar de Caralt Roy */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "funcio.h"



int main(void){
    
    int iter, index;
    double tol, x;
    

    printf("Per fer Newton-Raphson és necessari introduir unes dades: \n"); 
    printf("1- valor inicial \n");  
    printf("2- tolerància \n");
    printf("3- número d'iteracions que es vulguin realitzar...\n");
    scanf("%lf %lf %d", &x, &tol, &iter);
    index = newton(&x, tol, iter);
    if(index == 0){
        printf("ha convergit en el punt x = %24.16e de la funció\n", x);
    }
    else if(index == 1){
        printf("no ha convergit... \n");
    }
    

    return 0;
    
    
    /*Sabeu explicar les diferències de comportament de la convergència del mètode?
     
     Per a fer Newton s'escull un valor de l'abscissa pròxim a l'arrel. En aquest punt, es reemplaça la corba per la seva tangent, i es calcula el zero d'aquesta recta tangent. Aquest zero, normalment, és més pròxim al zero de la funció, que el valor inicial. Aquest procés es reitera, fins a arribar a una aproximació que es dona per bona. En el cas de la gràfica, a partir de x0, s'anirà trobant la successió x1 , x2 , . . ., etc, fins a arribar a un cert valor que es donarà com a solució de α 
     
     El mètode falla si s'anul·la la derivada en algun punt entre el valor del zero de la funció i el valor inicial. El nombre d'iteracions que siguin necessàries per a trobar l'arrel del polinomi, depén de la proximitat de l'aproximació inicial respecte al xero de la funció, per això en alguns casos es requereixen més iteracions que en d'altres ( es necessiten més iteracion pel valor inical 0.43, que pel -0.33 */
    
}




