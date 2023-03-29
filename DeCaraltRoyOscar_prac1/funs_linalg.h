/* Oscar de Caralt Roy */

#ifndef FUNS_LINALG_H_INCLUDED
#define FUNS_LINALG_H_INCLUDED

void resoltriinf (int n, double **L, double *x, double *b);
int resoltrisup(int n, double **A, double *b, double *x, double tol);
void prodMatVec (int m, int n, double **A, double *x, double *y);
double prod_esc (int dim, double* x, double* y);
int gauss(int n, double **A, double *b, double tol);
int gausspiv(int n, double **A, double *v, double tol);
double checkLU(int n, double **a, double **acp);
double generateACP(int n, double **A, double *b, double tol);
#endif
