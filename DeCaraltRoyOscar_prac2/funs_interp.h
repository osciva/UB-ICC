/* Oscar de Caralt Roy */

#ifndef FUNS_INTERP_H_INCLUDED 
#define FUNS_INTERP_H_INCLUDED

double horner(double z, double *x, double *c, int n);
int difdiv(double *x, double *f, int n);
double fun_log(double z);
double fun_runge(double z);

#endif
