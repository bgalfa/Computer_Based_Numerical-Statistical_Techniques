#include<stdio.h>
#include<math.h>
#define f(x,y) ((y-x)/(y+x))
int main()
{
printf(" Name: Bhavya Gupta \n Section: E \n Roll No.: 18 \n University Roll No.: 2018764 \n");
float x0, y0, xn, h, yn, slope,a,b;
int i, n;
printf("Enter Initial Condition\n");
printf("x0 = ");
scanf("%f", &x0);
printf("y0 = ");
scanf("%f", &y0);
printf("Enter calculation point xn = ");
scanf("%f", &xn);
printf("Enter number of intervals: ");
scanf("%d", &n);
h = (xn-x0)/n;
printf("The step length is: %.4f \n",h);
for(i=0; i < n; i++)
{
 slope = f(x0, y0);
 yn = y0 + h * slope;
 printf("x%d=%.4f \t y%d=%.4f \t slope%d=%0.4f \t yn at x%d=%.4f \n",i,x0,i,y0,i,slope,i,yn);
 y0 = yn;
 x0 = x0+h;
}
printf("Value of y at x = %0.2f is %0.3f \n",xn, yn);
return 0;
}