/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define var_name(var) #var

#include "gauss_elimination.h"


int main()
{
    int n;
    printf("Enter the number of data points");
    scanf("%d",&n);
    
    float data[n][4];
    printf("Enter the x,y values for each data point\n");
    
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&data[i][0],&data[i][1]);
        data[i][2]=data[i][0]*data[i][1];
        data[i][3]=powf(data[i][0],2);
    }

    float sumx=0,sumy=0,sumxy=0,sumsqx=0;
    float sum[]={sumx,sumy,sumxy,sumsqx};
    printf("\nThe given input data table is :\nx\ty\tx.y\tx^2\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%.2f\t",data[i][j]);
            sum[j]+=data[i][j];
        }
        printf("\n");
    }
printf("%s=%.2f ",var_name(sumx),sumx);
printf("%s=%.2f ",var_name(sumy),sumy);
printf("%s=%.2f ",var_name(sumxy),sumxy);
printf("%s=%.2f ",var_name(sumsqx),sumsqx);
}*/

#include<stdio.h>
int main()
{
 int n,o;
 printf(" Name: Bhavya Gupta \n Section: E \n Roll No.: 18 \n University Roll No.: 2018764 \n");
 printf("Enter the number of unknowns \n");
 scanf("%d",&n);
 float x[n],y[n],xy[n],x2[n];
 int i,j,k;
 float sx=0,sy=0,sx2=0,sxy=0,s=0,e=0,a,b,c,sum=0,d[n],A[n][n],yc,ans;
 for(i=0;i<n;i++)
 {
 printf("Enter the value of x[%d] and y[%d] \n",i,i);
 scanf("%f%f",&x[i],&y[i]);
 }
 for(i=0;i<n;i++)
 {
 xy[i]=x[i]*y[i];
 sxy=sxy+xy[i];
 x2[i]=x[i]*x[i];
 sx2=sx2+x2[i];
 sx=sx+x[i];
 sy=sy+y[i];
 }
 printf("x\ty\txy\tx^2\n");
 for(i=0;i<n;i++)
 {
 printf("%.2f\t%.2f\t%.2f\t%.2f\t",x[i],y[i],xy[i],x2[i]);
 printf("\n");
 }
 printf("Equation 1 is: %.2f = %d a + %.2f b \n",sy,n,sx);
 printf("Equation 2 is: %.2f = %.2f a + %.2f b \n",sxy,sx,sx2);
 printf("\nEnter the order of matrix: ");
scanf("%d", &o);
 printf("\nEnter the elements of augmented matrix row-wise:\n\n");
for (i = 1; i <= o; i++)
{
for (j = 1; j <= (o + 1); j++)
{
printf("A[%d][%d] : ", i, j);
scanf("%f", &A[i][j]);
}
}
for (i = 1; i <= o; i++)
{
for (j = 1; j <= (o+ 1); j++)
{
printf("%f\t", A[i][j]);
}
printf("\n");
}
for (j = 1; j <= o; j++)
{
for (i = 1; i <= o; i++)
{
if (i > j)
{
c = A[i][j] / A[j][j];
for (k = 1; k <= o + 1; k++)
{
A[i][k] = A[i][k] - c *A[j][k];
}
}
}
}
printf("Upper triangular matrix-> \n");
for (i = 1; i <= o; i++)
{
for (j = 1; j <= (o + 1); j++)
{
printf("%f\t", A[i][j]);
}
printf("\n");
}
d[o] = A[o][o + 1] / A[o][o];
for (i = o - 1; i >= 1; i--)
{
sum = 0;
for (j = i + 1; j <= o; j++)
{
sum = sum + A[i][j] *d[j];
}
d[i] = (A[i][o + 1] - sum) / A[i][i];
}
printf("\nThe solution is: \n");
for (i = 1; i <= o; i++)
{
printf("\n a%d=%f \t", i, d[i]);
a=d[1];
b=d[2];
}
 printf("a is %.4f and b is %.4f \n",a,b);
 printf("The generalized equation is : y=%.3f + %.3f x \n",a,b);
 printf("Enter the value of x at which y needs to be calculated : \n");
 scanf("%f",&yc);
 ans=a+b*yc;
 printf("The calculated y is %.2f \n",ans);
 return 0;
}