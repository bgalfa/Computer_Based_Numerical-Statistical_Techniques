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
    float y[n][n];
    printf("Enter the data points fro x and y");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i][0]);
    }
    float a;
    printf("Enter the value to find :");
    scanf("%f",&a);
    for(int col=1;col<n;col++)
    {
        int row;
        for( row=0;row<(n-col);row++)
        {
            y[row][col]= y[row+1][col-1] - y[row][col-1];
        }
    }
    printf("The forward difference table is :\n");
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n-row;col++)
        {
            printf("%d%d_%f\t",row,col,y[row][col]);
        }
        printf("\n");
    }
    float ya=y[n][0];
    float p=(a-x[n-1])/(x[1]-x[0]);
    float u=p;
    
    for(int i=1;i<n;i++)
    {

        float s=u*y[n-i-1][i]/factorial(i);
        ya+=s;
        printf("%.3f*%.3f/%d=%.3f\n",u,y[n-i-1][i],factorial(i),s);
        u=u*(p+i);
    }
    printf("at x=%.2f y=%.2f",a,ya);

}