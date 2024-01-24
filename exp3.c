/*
METHOD of False Position/ Regula Falsi Method
1.Solution of Algebraic and Transcendental equations.
2. Non linear equation.
3. Rate of convergence is faster compared to bisection method

c=  (a.f(b)-b.f(a))/(f(b)-f(a))
Algorithm:
    1. Find/Guess the interval [a,b] such that f(a).f(b)<0
    2. Find c as given above.
    3.  a.If f(a).f(c)<0 roots +ve ->[a,c]
        b. f(b).f(c)<0 roots -ve ->[c,b]
    4. Repeat steps 1 and 2.
*/
#include<stdio.h>
#include<math.h>
#define max_it 100
float fx(float x)
{
    return powf(x,3)-2*x-5;
}
int main()
{
    printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");
    float a,b,c;
    printf("The given equation is: x^3-2x-5");
    while(1){
        printf("\nInput the first guesses a and b: ");
        scanf("%f %f",&a,&b);
        if((fx(a)*fx(b))<0)
        {    
            c = (a*fx(b)-b*fx(a))/(fx(b)-fx(a));
            if(fx(a)*fx(c)<0)
                b=c;
            else if(fx(b)*fx(c)<0)
                a=c;
            break;
        }
        else
            printf("\nIncorrect guesses, please input again");
    }
    int p=0;
    printf("Input the decimal approximation : ");
    scanf("%d",&p);
    int i=1;
    float temp=c;
    while(i<max_it)
    {
        c = (a*fx(b)-b*fx(a))/(fx(b)-fx(a));
        if(temp==c)
            break;
        if(fx(a)*fx(c)<0)
        {
            b=c;
        }
        else if(fx(b)*fx(c)<0)
        {
            a=c;
        }
        temp=c;
        printf("\nIteration %d c=%f, f(c)=%f ",i,c,fx(c),a,b);
        i++;
    }
    printf("\nThe final answer is %f, came in the iteration number : %d",c,i+1);
}