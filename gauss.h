#ifndef GAUSS_H_
#define GAUSS_H_
void prepare(double **matrix, int n, double *b);
void gauss(int n, double *b, double *x, double eps, double &epsf, double *epsv);
#endif
