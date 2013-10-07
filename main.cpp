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
        try {
            if(type==1)
                    gauss(matrix,n,b,x,eps,epsf);
            if(type==2) 
                    itern(matrix,n,b,x,eps,epsf);
            cout << "x: ";
            for(int i=0;i<n;i++) {
                cout <<x[i] << ' ';
                    delete[] matrix[i];
            }
            cout << "\neps : " << epsf << endl;
            delete[] matrix;
            delete[] b;
            delete[] x;
        }
        catch (exception e) {
            cerr << e.what() << endl;
        }
                
        return 0;
}
