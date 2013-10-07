#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
void gauss(double **matrix, int n, double *b, double *x, double eps, double &epsf)
{
    double det=1;
    int i,j;
    for(int k = 0; k < n ; k++)
    {
        det*=matrix[k][k];
        for(j = k + 1; j < n; j++)
        {
            matrix[k][j]=matrix[k][j]/matrix[k][k];
        }
        b[k]=b[k]/matrix[k][k];
        matrix[k][k]=1;
        for(i = k + 1; i < n; i++)
        {
            if(matrix[i][k] != 0)
                for(j = k + 1; j < n; j++)
                {
                    matrix[i][j] = matrix[i][j] - matrix[i][k]*matrix[k][j];
                }
            b[i]    = b[i] - matrix[i][k]*b[k];
            matrix[i][k] = 0;
        }

//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//                std::cout<<matrix[i][j]<<' ';
//            std::cout<<b[i];
//            std::cout<<'\n';
//        }
//        std::cout<<"<<<<<<<<<<<<<<<<<<<<<<"<<'\n';
    }
    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<n;j++)
            sum+=matrix[i][j]*x[j];
        x[i]=b[i]-sum;
    }
    cout<<det;
}

