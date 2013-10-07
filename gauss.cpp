#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
double **matrixG;
double *bG;
double detG;
void prepare(double **matrix, int n, double *b)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<' ';
        cout<<b[i]<<'\n';
    }
    cout<<"<<<<<<<<<<<<<<<<<<"<<'\n';
    double **temMatrix;
    double *bb= new double[n];
    for(int i=0;i<n;i++)
        bb[i]=b[i];
    b=bb;
    temMatrix=new double*[n];
    for(int i=0;i<n;i++)
    {
            temMatrix[i]= new double[n];
            for(int j=0;j<n;j++) {
                temMatrix[i][j]=matrix[i][j];
            }
    }
    matrix=temMatrix;
    detG=1;
    int i,j;
    for(int k = 0; k < n ; k++)
    {
        detG*=matrix[k][k];
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

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<matrix[i][j]<<' ';
            cout<<b[i]<<'\n';
        }
        cout<<">>>>>>>>>>>>>>>>>>>>>"<<'\n';
    }
    matrixG=matrix;
    bG=b;
}

void gauss(int n, double *b, double *x, double eps, double &epsf, double *epsv,bool e)
{
    if(!e)
        b=bG;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrixG[i][j]<<' ';
        cout<<b[i]<<'\n';
    }
    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<n;j++)
            sum+=matrixG[i][j]*x[j];
        x[i]=b[i]-sum;
    }
}

double det()
{
    return detG;
}

