#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
double **matrixOld;
double **matrixG;
double **bG;
double **bOld;
double detG;
void prepare(double **matrix, int n, double **b,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<' ';
        //cout<<b[i]<<'\n';
    }
    matrixOld=matrix;
    cout<<"<<<<<<<<<<<<<<<<<<"<<'\n';
    double **temMatrix;
    double **bb=new double*[m];
    for(int i=0;i<m;i++)
    {
            bb[i]= new double[n];
            for(int j=0;j<n;j++) {
                bb[i][j]=b[i][j];
            }
    }
    bOld=b;
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
        for(int l=0;l<m;l++)
                b[l][k]=b[l][k]/matrix[k][k];
        matrix[k][k]=1;
        for(i = k + 1; i < n; i++)
        {
            if(matrix[i][k] != 0)
                for(j = k + 1; j < n; j++)
                {
                    matrix[i][j] = matrix[i][j] - matrix[i][k]*matrix[k][j];
                }
                
            for(int l=0;l<m;l++)
                b[l][i]    = b[l][i] - matrix[i][k]*b[l][k];
            matrix[i][k] = 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<matrix[i][j]<<' ';
                
            for(int l=0;l<m;l++)
                cout<<b[l][i]<<' ';
            cout<<'\n';
        }
        cout<<">>>>>>>>>>>>>>>>>>>>>"<<'\n';
    }
    matrixG=matrix;
    bG = new double*[m];
    for(int l=0;l<m;l++)
            bG[l]=b[l];
}

void gauss(int n, double *b, double *x, double eps, double &epsf, double *epsv,int m)
{
    b=bG[m];

    for(int i=n-1;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<n;j++)
            sum+=matrixG[i][j]*x[j];
        x[i]=b[i]-sum;
    }
    double *newB= new double[n];
    for(int i=0;i<n;i++)
    {
        newB[i]=0;
        for(int j=0;j<n;j++)
        {
            newB[i]+=matrixOld[i][j]*x[j];
        }
            epsv[i]=bOld[m][i]-newB[i];
            epsf += pow(epsv[i],2);
    }
        epsf = sqrt(epsf);
   
}

double det()
{
    return detG;
}

