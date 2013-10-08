#ifndef GAUSS_H_
#define GAUSS_H_
void prepare(double **matrix, int n, double **b,int m=1);
void gauss(int n, double *b, double *x, double eps, double &epsf, double *epsv, int m=0);
double det();
#endif
