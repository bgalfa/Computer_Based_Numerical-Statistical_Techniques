/*
NEWTON RAPHSON METHOD (NRM)

NRM -> x{n+1}=x{n}-f(x{n})/f'(x{n})
1. Define the equation of curve
2. Choose two initial guesses such that f(a).f(b)<0
3. Choose x0 from a & b whose value f(a) and f(b) nearer to 0.
4. To find the value of xn such that it gives the approximate f(x{n+1})
    Evaluate using the formula given above else repeat the steps.
*/
#include<stdio.h>
#include<math.h>
float fx(float x)
{
    return powf(x,3)-3*x-5;
}
float derivative_fx(float x)
{
    return 3*powf(x,2)-3;
}
float findx0(float a,float b)
{
    if(a==b)
        return a;
    else if(fabs(a)<fabs(b))
        return a;
    else 
        return b;
}
int main()
{
 printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");
    float a,b,prev=0,x;
    printf("The given equation is: x^3-3x-5");
    while(1){
        printf("\nInput the first guesses a and b: ");
        scanf("%f %f",&a,&b);
        if((fx(a)*fx(b))<0)
        {    
            x=findx0(a,b);
            break;
        }
        else
            printf("\nIncorrect guesses, please input again");
    }
    float error_limit;
    printf("\nEnter the error limit");
    scanf("%f",&error_limit);
    float error=0;
    int iter=0;
    printf("Iteration\tx\tf(x)\terror");
    printf("\n%d\t%f\t%f\t%f",iter++,x,fx(x),error);
    do
    {
        prev=x;
        x=prev-fx(prev)/derivative_fx(prev);
        error=fabs(prev-x);
        printf("\n%d\t%f\t%f\t%f",iter,x,fx(x),error);
        iter++;
    } while (error>error_limit && iter<10);
    printf("\n\nThe final answer is: %f and  came in iteration no: %d",x,iter);
}