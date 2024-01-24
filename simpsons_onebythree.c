#include<math.h>
#include<stdio.h>
float function(float x)
{
    return 1/(1+powf(x,2));
}
int main()
{
    int n;
    printf("Enter the no of data points :");
    scanf("%d",&n);
    float x[n];
    float y[n];

    printf("Enter the data values for x:");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
        y[i]=function(x[i]);
    }
    float h;
    printf("Enter the value of h:");
    scanf("%f",&h);
    float y_odd=0,y_even=0;
    for(int i=1;i<n-1;i++)
    {
        if(i%2==0)
            y_even+=y[i];
        else   
            y_odd+=y[i];
    }
    float integ=0;
    integ=(y[0]+y[n-1]+2*y_even+4*y_odd)*h/3;
    printf("Final aintegration is :%f",integ);


}
