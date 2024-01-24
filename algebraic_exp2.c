//EXPERIMENT 2
//BISECTION METHOD
/*
1. Solution of Algebraic and Transcendental equations.
2. Non linear equation.
3. Repeated application of Intermediate value property

Algorithm:
    1.Start
    2. Define function x
    3. Choose initial guesses x0 and x1 such that f(x0).f(x1)<0
    4. Choose prespecified tolerable error e
    5. Calculate new approximate root x2=(x0+x1)/2;
    6. Calculate f(x0).f(x2)
        a. f(x0)f(x2)<0 x0=x0 & x1=x2
        b. f(x0)f(x2)>0 x0=x2 & x1=x1
        c. f(x0)f(x2)=0, x2= root.
    7. If(|f(x2)|>e) then goto step 5 else goto 8;
    8. Display x2 as output

    GIVEN PROBLEM:
        x^3-x-4=0;
*/
#include<stdio.h>
#include<math.h>
float solve_eq(float x)
{
    return pow(x,3)-x-4;
}
int main()
{
   printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");
    float x0,x1,e,x2;
    printf("The given equation is : x^3-x-4=0");
    printf("\nInput the values of x0 and x1 :");
    while(1){
        scanf("%f%f",&x0,&x1);
        if(solve_eq(x0)*solve_eq(x1)<0)
            break;
        else
            printf("Invalid Input, enter again");
    }
    printf("\nEnter the tolerable error e :");
    scanf("%f",&e);
    int i=0;
    do
    {
        x2=(x0+x1)/2;
        float prod=solve_eq(x0)*solve_eq(x2);
        if(prod<0)
        {
            x1=x2;
        }
        else if(prod>0)
        {
            x0=x2;
        }
        else if(prod==0)
            break;
        i++;
        printf("\nIteration %d, f(%f) is %f",i,x2,solve_eq(x2));
    }while(fabs(solve_eq(x2))>e);
    printf("\nThe final approximation is : %f",x2);
}