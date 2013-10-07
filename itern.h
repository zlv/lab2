#ifndef ITERN_H_
#define ITERN_H_
void itern(double **matrix, int n, double *b, double *x, double eps, double &epsf, double *epsv);
void iternInversed(double **a, int n, double **result, double eps, double &epsf, double *epsv);
#endif
