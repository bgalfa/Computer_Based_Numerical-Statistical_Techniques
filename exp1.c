//To implement quadratic equations
/*
Using shridharacharya(quadratic formula)

Input coefficients from the use:-
1. print the final equation.
2. print the determinant and which condition it satisfies.
3. find the roots using quadratic formula and print them.

ax^2+bx+c=0;
quadratic formula, x=(-b+-(b^2-4ac)^(1/2))/2a;
*/
#include<stdio.h>
#include<math.h>
int main()
{
printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");
    float a,b,c;
    printf("Enter the coefficients of x^2, x and the constant :");
    scanf("%f%f%f",&a,&b,&c);
    printf("The final equation is :%.2fx^2 + %.2fx + %.2f\n",a,b,c);

    float D=pow(b,2)-4*a*c;
    printf("Determinant value is: %.2f\n",D);
    float root1,root2;
    if(D>0)
    {    
        root1=(-b+sqrt(D))/(2*a);
        root2=(-b-sqrt(D))/(2*a);
        printf("The given equation has real and distinct roots, these are %.2f and %.2f\n",root1,root2);
    }
    else if(D==0)
    {    
        root1=(-b+sqrt(D))/(2*a);
        printf("The given equation has same roots, it is %.2f\n",root1);
    }
    else
    {
        float x1=-b/(2*a),x2=sqrt(-D)/(2*a);
        printf("The given equation has imaginary roots,\n and they are %.2f - %.2fi and %.2f + %.2fi\n",x1,x2,x1,x2);
    }
}