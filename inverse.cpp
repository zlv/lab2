#include "itern.h"
#include "gauss.h"
#include <iostream>
using namespace std;
void inversed(int t, double **a, int n, double **result, double eps, double &epsf, double *epsv) {
    double *e = new double[n];
    double *temp = new double[n];
    for (int i=0; i<n; i++)
        e[i] = 0;
    e[0]=1;
    for (int i=0; i<n; i++) {
        if (i!=0)
            e[i-1] = 0;
        e[i] = 1;
        if (t==1) {

            prepare(a,n,e);
            gauss(n,e,temp,eps,epsf,epsv);
        }
        else
            itern(a,n,e,temp,eps,epsf,epsv);
        for (int j=0; j<n; j++)
            result[j][i] = temp[j];
        cout << "\nepsilon vector: ";
        for(int i=0;i<n;i++)
            cout << epsv[i] << ' ';
        cout << "\neps : " << epsf << endl;
    }
    delete[] temp;
    delete[] e;
}

