#include<stdio.h>

int factorial(int x)
{
    int prod=1;
    for(int i=1;i<=x;i++)
    {
        prod=prod*i;
    }
    return prod;
}
int main()
{
    int n;
    printf("Enter no of entries");
    scanf("%d",&n);
    float x[n];
    float y[n];
    printf("Enter the data points fro x and y");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    float a;
    printf("Enter the value to find :");
    scanf("%f",&a);
    
    float sum=0;
    for(int i=0;i<n;i++)
    {
        float prod=1;
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            prod=prod*(a-x[j])/(x[i]-x[j]);
            printf("%f\t",prod);
        }
        printf("%.3f\n",prod*y[i]);
        sum+=prod*y[i];
    }
    printf("at x=%.2f the value of y =%.3f",a,sum);
}