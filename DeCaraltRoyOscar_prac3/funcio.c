/* Oscar de Caralt Roy */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "funcio.h"



          
float hornerfun (double *coef, double x){ /* Aquesta funció l'havia fet per aplicar horner en el polinomi de l'enunciat, però no aconseguia que convergís, si posava 50 iteracions sempre feia 50 iteracions i després s'imprimia el missatge de: no ha convergit, si posava 1000 iteracions, el mateix... */
    int i;
    float sum ;
    sum = coef[0];
    for (i = 0; i <= 6; i++){
        sum = sum * x + coef[i];
    }
    return sum ;
}

float hornerder (double *coef, double x){ /* Aquesta funció l'havia fet per aplicar horner en el polinomi obtingut de derivar la funció f(x), però no aconseguia que convergís, si posava 50 iteracions sempre feia 50 iteracions i després s'imprimia el missatge de: no ha convergit, si posava 1000 iteracions, el mateix... */
    int i;
    float sum ;
    sum = coef[0];
    for (i = 1; i <= 5; i++){
        sum = sum * x + coef[i];
    }
    return sum ;
}



double fun(double x){ /* entre comentaris està el codi amb el que havia intentant aplicar horner, però no aconseguia que convergís, si posava 50 iteracions sempre feia 50 iteracions i després s'imprimia el missatge de: no ha convergit, si posava 1000 iteracions, el mateix... */    
    double f, aux;
    aux = x * x; /* declarem una variable aux = x*x per a fer menys pasos computacionals */ 
    
    f = 9261 * (aux * aux * aux) - 4116*(aux * aux * x) + 7931*(aux * aux) - 3624*(aux * x) - 1285*(aux) +492 * x + 45; 
    
     
 /* double coef[]={9261, -4116, 7931, -3624, -1285, 492, 45};*/
 /* return hornerfun(coef,x);*/
    return f;
 
}

double der(double x){ /* derivada de la funció f(x) ---> f'(x)*//* entre comentaris està el codi amb el que havia intentant aplicar horner, però no aconseguia que convergís, si posava 50 iteracions sempre feia 50 iteracions i després s'imprimia el missatge de: no ha convergit, si posava 1000 iteracions, el mateix... */
    double f, aux;
    aux = x * x; /* declarem una variable aux = x*x per a fer menys pasos computacionals */ 
    
    f = 55566 *(aux * aux * x) - 20580 * (aux * aux) + 31724 *(aux * x) - 10872 * aux - 2570 * x + 492;
    

 /* double coef[]={55566, -20580, 31724, -10872, -2570, 492};*/
 /* return hornerder(coef,x);*/
    return f; 
 
}


int newton(double *x, double tol, int iter){
    
     
	int i;
    
    i = 0; /* iter: nombre d'iteracions*/

	do{   /* iterar mentres el valor d'x no sigui més gran que la tolerància o no haguem fet les iteracions necessàries seguim iterant*/
        
        if(fabs(der(*x)) < tol){
            return 1;
        }
        
        i++;
        
		*x = *x - (fun(*x)/der(*x));  
        printf("i = %2d   ||  x = %+24.16e  ||  valor funció = %+24.16e  ||  valor derivada  = %+24.16e  ||  increment = %+24.16e\n", i, *x, fun(*x), der(*x), fun(*x)/der(*x));

        
	}while(i <= iter && fabs(fun(*x)/der(*x))>tol);
	
	if (i > iter){
        return 1;
        }
    else{
        return 0;
    }

}
