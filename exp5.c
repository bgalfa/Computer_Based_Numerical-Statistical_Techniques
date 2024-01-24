/*
SECANT METHOD

ALGORITHM:
1. Input the guesses x0 and x1 such that f(x0).f(x1)<1
    and the error limit(e) and the number of iterations.
2. Calculate x2=x1-f(x1)*((x1-x0)/(f(x1)-f(x0)));
3. if f(x2)>e then set x0=x1 and x1=x2
    then goto Step 2.
    else: print x2 is the root;

Equation: f(x)=Cos(x)+2*Sin(x)+x^2
ans= -0.6595
*/
#include<stdio.h>
#include<math.h>
float fx(float x)
{
    return cosf(x)+2*sinf(x)+powf(x,2);
}
float findx2(float x1,float x0)
{
    return x1-fx(x1)*(x1-x0)/(fx(x1)-fx(x0));
}
int main()
{
 printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");
    float x0,x1,x2;
    printf("The equation to solve is :Cos(x)+2*Sin(x)+x^2=0");
    while(1)
    {
        printf("\nEnter the initial guesses :");
        scanf("%f%f",&x0,&x1);
        if(fx(x0)*fx(x1)<0)
            break;
        else
            printf("Incorrect initial guesses, input again!");
    }
    if(x0>x1)
    {
        int t=x0;
        x0=x1;
        x1=t;
    }
    int max_it,it=0;
    printf("Enter the number of iterations:");
    scanf("%d",&max_it);
    float e;
    printf("Enter the error limit :");
    scanf("%f",&e);
    float error=e+1;
    printf("Iteration\t x2 \t f(x2) \t error");
    while(error>e && it<max_it)
    {
        x2=findx2(x1,x0);
        error=fabs(fabs(x2)-fabs(x1));
        if(fabs(fx(x2))>e)
        {
            x0=x1;
            x1=x2;
        }
        else
            break;
        printf("\n%d\t%f\t%f\t%f",it,x2,fx(x2),error);
        it++;
    }

}
