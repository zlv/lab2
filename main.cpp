#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include "gauss.h"
#include "itern.h"
#include "inverse.h"
#include <stdexcept>
using namespace std;
int solveType = 1;
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
        cout << "matrix input:\n";
        for(int i=0;i<n;i++)
        {
                matrix[i]= new double[n];
                for(int j=0;j<n;j++) {
                        cin >> matrix[i][j];
                        cout << matrix[i][j] << ' ';
                }
                cin>>b[i];
                cout << endl;
        }
        double eps=1e-3;
        double epsf;
        double *epsv = new double[n];
        try {
            double **result;
            if(type==1) {
                if (solveType==1) {
                    prepare(matrix,n,b);
                    gauss(n,b,x,eps,epsf,epsv);
                    cout<<"det: "<<det()<<'\n';
                }
                else {
                    itern(matrix,n,b,x,eps,epsf,epsv);
                }
                cout << "x: ";
                for(int i=0;i<n;i++)
                    cout <<x[i] << ' ';
                cout << "\nepsilon vector: ";
                for(int i=0;i<n;i++)
                    cout << epsv[i] << ' ';
                cout << "\neps : " << epsf << endl;
            }
            else if (type==2) {
            }
            else if (type==3) {
                result=new double*[n];
                for(int i=0;i<n;i++)
                    result[i]= new double[n];
                inversed(solveType,matrix,n,result,eps,epsf,epsv);
                cout << "\nreversed matrix : " << endl;
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++)
                        cout << result[i][j] << ' ';
                    cout << endl;
                }
                cout << endl;
            }
            for (int i=0; i<n; i++) {
                delete[] matrix[i];
                if (type==3)
                    delete[] result[i];
            }
            delete[] matrix;
            if (type==3)
                delete[] result;
            delete[] b;
            delete[] x;
        }
        catch (invalid_argument e) {
            cerr << e.what() << endl;
        }
                
        return 0;
}
