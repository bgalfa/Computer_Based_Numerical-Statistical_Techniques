// #include<stdio.h>
// #include<math.h>
// #define f(x) 1/(1+pow(x,2))
// int main()
// {
// float b, a, I=0.0,h,y,k;
// int i,n;
//  printf(" Name: Bhavya Gupta \n Section: E \n Roll No.: 18 \n University Roll No.: 2018764 \n");
// printf("Enter lower limit of integration: \n");
// scanf("%f", &a);
// printf("Enter upper limit of integration: \n");
// scanf("%f", &b);
// printf("Enter number of intervals: \n");
// scanf("%d", &n);
// h = (b-a)/n;
// printf("step length is: %.2f \n",h);
// I = (f(a) + f(b))/2;
// for(i=1; i<n; i++)
// {
//  k = a+i*h;
//  y=f(k);
//  I = I+f(k);
//  printf("for x%d=%.2f y%d=%.2f \n",i,k,i,y);
// }
// printf("for x%d=%.2f y%d=%.2f \n",i,k+h,i,f(b));
// I = I * h;
// printf("Required value of integration is: %.3f \n", I);
// return 0;
// }

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no of data points :");
    scanf("%d",&n);
    float x[n];
    float y[n];

    printf("Enter the data values for x and y");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    float h;
    printf("Enter the value of h:");
    scanf("%f",&h);
    float y_n=0;
    for(int i=1;i<n-1;i++)
        y_n+=y[i];
    float integ=0;
    integ=(y[0]+y[n-1]+2*y_n)*h/2;
    printf("Final aintegration is :%f",integ);


}
















