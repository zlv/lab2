#include <stdexcept>
#include <math.h>
#include <iostream>
using namespace std;
void itern(double **a, int n, double *b, double *x, double eps, double &epsf, double *epsv) {
    double *betta = new double[n];
    double **alpha = new double*[n];
    double normalpha = 0;
    cout << "alpha:\n";
    for (int i=0; i<n; i++) {
        double sum = 0;
        betta[i] = b[i]/a[i][i];
        alpha[i] = new double[n];
        if (a[i][i]) {
            for (int j=0; j<n; j++) {
                if (i!=j) {
                    sum += fabs(a[i][j]);
                    alpha[i][j] = -a[i][j]/a[i][i];
                }
                else {
                    alpha[i][j] = 0;
                }
                cout << alpha[i][j] << ' ';
                normalpha += pow(alpha[i][j],2);
            }
            cout << endl;
        }
        if (fabs(a[i][i])<=sum) {
            delete[] betta;
            for (int j=0; j<i; j++) 
                delete[] alpha[j];
            delete[] alpha;
            throw invalid_argument("Wrong matrix. should be |a[i][i]| > sum(a[i][j])");
        }
    }
    normalpha = sqrt(normalpha);
    cout << "norma alpha: " << normalpha << '\n';
    double *oldx = new double[n];
    cout << "betta: ";
    for (int i=0; i<n; i++) {
        x[i] = betta[i];
        cout << x[i] << " ";
    }
    cout << endl;
    //int count = 0;
    while (1) {
        for (int i=0; i<n; i++)
            oldx[i] = x[i];
        for (int i=0; i<n; i++) {
            double product = 0;
            for (int j=0; j<n; j++)
                product += alpha[i][j]*oldx[j];
            x[i] = betta[i]+product;
        }
        epsf = 0;
        for (int i=0; i<n; i++) {
            epsv[i] = x[i]-oldx[i];
            epsf += pow(epsv[i],2);
        }
        epsf = sqrt(epsf);
        if (epsf<(1-normalpha)*eps/normalpha) break;
    }
    delete[] oldx;
    delete[] betta;
    for (int i=0; i<n; i++) 
        delete[] alpha[i];
    delete[] alpha;
}

