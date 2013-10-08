#include "itern.h"
#include "gauss.h"
#include <iostream>
using namespace std;
void inversed(int t, double **a, int n, double **result, double eps, double &epsf, double *epsv) {
    double *temp = new double[n];
    double **epsm = new double*[n];
    double **em = new double*[n];
    for (int i=0; i<n; i++) {
        epsm[i] = new double[n];
        em[i] = new double[n];
        for (int j=0; j<n; j++)
            em[i][j] = 0;
        em[i][i] = 1;
    }
    if (t==1)
        prepare(a,n,em,n);
    for (int i=0; i<n; i++) {
        if (t==1) {
            gauss(n,em[i],temp,eps,epsf,epsv,i);
        }
        else
            itern(a,n,em[i],temp,eps,epsf,epsv);
        for (int j=0; j<n; j++) {
            result[j][i] = temp[j];
            epsm[j][i] = epsv[j];
        }
    }
    cout << "\nepsilon matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << epsm[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "\neps : " << epsf << endl;
    delete[] temp;
    for (int i=0; i<n; i++) {
        delete[] epsm[i];
        delete[] em[i];
    }
    delete[] epsm;
    delete[] em;
}

