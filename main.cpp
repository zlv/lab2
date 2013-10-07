#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include "gauss.h"
#include "itern.h"
using namespace std;
int main(int argc, char **argv) {
        int type;
        int n;
        double **matrix;
        double *b;
        cin >>type;
        cin >> n;
        double *x = new double[n];
        matrix=new double*[n];
        b= new double[n];
        for(int i=0;i<n;i++)
        {
                matrix[i]= new double[n];
                for(int j=0;j<n;j++)
                        cin >> matrix[i][j];
                cin>>b[i];
        }
        double eps=1e-3;
        double epsf;
        double *epsv = new double[n];
        try {
            //if(type==1)
                    //gauss(matrix,n,b,x,eps,epsf);
            if(type==2) {
                itern(matrix,n,b,x,eps,epsf,epsv);
            }
            cout << "x: ";
            for(int i=0;i<n;i++)
                cout <<x[i] << ' ';
            cout << "\nepsilon vector: ";
            for(int i=0;i<n;i++)
                cout << epsv[i] << ' ';
            cout << "\neps : " << epsf << endl;
            double **result=new double*[n];
            for(int i=0;i<n;i++)
                result[i]= new double[n];
            iternInversed(matrix,n,result,eps,epsf,epsv);
            cout << "\nreversed matrix : " << endl;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++)
                    cout << result[i][j] << ' ';
                cout << endl;
            }
            cout << endl;
            for (int i=0; i<n; i++) {
                delete[] matrix[i];
                delete[] result[i];
            }
            delete[] matrix;
            delete[] result;
            delete[] b;
            delete[] x;
        }
        catch (exception e) {
            cerr << e.what() << endl;
        }
                
        return 0;
}
