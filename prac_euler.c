#include<stdio.h>
float function(float x,float y)
{
    return (y-x)/(y+x);
}
int main()
{
    float y,x;
    float h;
    int n;
    printf("Enter the initial values: ");
    scanf("%f%f",&x,&y);
    printf("Enter the no of intervals:");
    scanf("%d",&n);
    float a;
    printf("Enter point at which y is to be found:");
    scanf("%f",&a);
    h=(a-x)/(float)n;
    for(int i=0;i<n;i++)
    {
        y=y+h*function((x+i*h),y);
    }
    printf("The final value is %f",y);

}