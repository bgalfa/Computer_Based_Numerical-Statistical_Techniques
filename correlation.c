#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the no of data points");
    scanf("%d",&n);
    int x[n];
    int y[n];
    int x_avg=0,y_avg=0;
    printf("Enter the x and y values:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x_avg+=x[i];
        y_avg+=y[i];
    }
    x_avg/=n;
    y_avg/=n;
    float sumd2x=0,sumd2y=0,sumdxdy=0;
    for(int i=0;i<n;i++)
    {
        sumdxdy+=(x[i]-x_avg)*(y[i]-y_avg);
        sumd2x+=pow((x[i]-x_avg),2);
        sumd2y+=pow((y[i]-y_avg),2);
    }

    float sdx=pow((float)(sumd2x/n),0.5);
    float sdy=pow((float)(sumd2y/n),0.5);    
    float corr;
    printf("d2x=%f\td2y=%f\tdxdy=%f\nvar(x)=%f\tvar(y)=%f\n",sumd2x,sumd2y,sumdxdy,sdx,sdy);
    corr=(float)sumdxdy/(n*sdx*sdy);
    printf("Correlation of the above data point is: %.2f",corr);

    float regxy=corr*sdx/sdy;
    float regyx=corr*sdy/sdx;
    printf("Regression xy=%f\nRegression yx= %.2f",regxy,regyx);
}