// #include<stdio.h>
// #include<math.h>
// #define f(x) 1/(1+pow(x,2))
// int main()
// {
// float b, a, I=0.0,h,y,k;
// int i,n;
// printf(" Name: Bhavya Gupta \n Section: E \n Roll No.: 18 \n University Roll No.: 2018764 \n");
// printf("Enter lower limit of integration: \n");
// scanf("%f", &a);
// printf("Enter upper limit of integration: \n");
// scanf("%f", &b);
// printf("Enter number of intervals: \n");
// scanf("%d", &n);
// h = (b-a)/n;
// printf("step length is: %.2f \n",h);
// I = f(a) + f(b);
// for(i=1; i<n; i++)
// {
//  k = a+i*h;
//  y=f(k);
//  if(i%3==0)
//  { I = I+2*f(k); }
//  else
//  { I=I+3*f(k);}
//  printf("for x%d=%.2f y%d=%.2f \n",i,k,i,y); }
// printf("for x%d=%.2f y%d=%.2f \n",i,k+h,i,f(b));
// I = I * 3*h/8;
// printf("Required value of integration is: %.3f \n", I);
// return 0; }
#include<math.h>
#include<stdio.h>
float function(float x)
{
    return 1/(1+powf(x,2));
}
int main()
{
    int n;
    printf("Enter the no of intervals h :");
    scanf("%d",&n);
    n++;
    float h;

    float x[n];
    float y[n];
    printf("Enter the lower and upper limit of x:");
    scanf("%f%f",&x[0],&x[n-1]);
    h=(x[n-1]-x[0])/(n-1);
    printf("%f\n",h);
    for(int i=0;i<n;i++)
    {
        x[i]=x[0]+i*h;
        y[i]=function(x[i]);
        printf("%f %f\n",x[i],y[i]);
    }
    
    float y_rest=0,y_three=0;
    for(int i=1;i<n-1;i++)
    {
        if(i%3==0)
            y_three+=y[i];
        else   
            y_rest+=y[i];
    }
    float integ=0;
    integ=(y[0]+y[n-1]+3*y_rest+2*y_three)*3*h/8;
    printf("Final integration is :%f",integ);
}
