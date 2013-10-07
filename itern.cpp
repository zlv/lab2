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
        else if (a[i][i]<=sum) {
            delete[] betta;
            for (int i=0; i<n; i++) 
                delete[] alpha[i];
            delete[] alpha;
            throw invalid_argument("Wrong matrix. |a[i][i]| should be > sum(a[i][j])");
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
        //cerr << "x" << count++ << ": ";
        //for (int i=0; i<n; i++)
            //cerr << x[i] << ' ';
        //cerr << endl;
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

void iternInversed(double **a, int n, double **result, double eps, double &epsf, double *epsv) {
    double *e = new double[n];
    double *temp = new double[n];
    for (int i=0; i<n; i++)
        e[i] = 0;
    for (int i=0; i<n; i++) {
        if (i!=0)
            e[i-1] = 0;
        e[i] = 1;
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
