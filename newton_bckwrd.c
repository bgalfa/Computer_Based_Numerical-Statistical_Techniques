#include <stdio.h>
void BackWard(float x[10], float y[10][10], int n)
{
int i, j;
float a ;
 printf(" Enter the value of a :\n");
scanf("%f",&a);
float h, u, sum, p;
for (j = 1; j < n; j++) {
for (i = j; i < n; i++) {
y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
} }
printf("\nThe backward difference table is:\n");
for (i = 0; i < n; i++) {
printf("\n");
for (j = 0; j <= i; j++) {
printf("%f\t", y[i][j]);
} }
p = 1.0;
sum = y[n - 1][0];
h = x[1] - x[0];
u = (a - x[n - 1]) / h;
for (j = 1; j < n; j++) {
p = p * (u + j - 1) / j;
sum = sum + p * y[n - 1][j];
}
printf("\nThe value of y at x=%0.1f is %0.3f \n", a, sum);
}
int main()
{
int i,n,j;
 printf(" Name: Bhavya Gupta \n Section: E \n Roll No.: 18 \n University Roll No.: 2018764 \n");
printf(" Enter number of observations \n");
scanf("%d",&n);
float x[10] ;
printf(" Enter the values of x: \n");
for(i=0;i<n;i++)
{
scanf("%f",&x[i]);
}
float y[10][10];
 printf(" Enter the values of y:\n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<1;j++)
 {
 scanf("%f",&y[i][j]);
 }
 }
 for(i=0;i<n;i++)
 {
 for(j=1;j<n;j++)
 {
 y[i][j]=0;
 } }
 BackWard(x,y,n);
 return 0; }