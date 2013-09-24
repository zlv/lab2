#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
int main(int argc, char **argv) {
        int type;
        int n;
        double **matrix;
        double *b;
        cin >>type;
        cin >> n;
        matrix=new double*[n];
        b= new double[n];
        for(int i=0;i<n;i++)
        {
                matrix[i]= new double[n];
                for(int j=0;j<n;j++)
                        cin >> matrix[i][j];
                cin>>b[i];
        }
        if(type==1)
                gauss(matrix,b,eps,normeps);
        if(type==2) 
                
        return 0;
}
