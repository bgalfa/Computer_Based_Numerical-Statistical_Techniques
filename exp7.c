/*
Method Name- Gauss Jordan
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");

    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    /* 2. Reading Augmented Matrix */
    printf("Enter Coefficients of Augmented Matrix:\n");
    for (i = 1; i <= n; i++) {
        printf("\nROW %d:",i);
        for (j = 1; j <= n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (i = 1; i <= n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 1; j <= n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    printf("AFTER ROW OPERATIONS Diagonal Matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n+1;j++)
            printf("%.2f ",a[i][j]);
        printf("\n");
    }
    /* Obtaining Solution */
    for (i = 1; i <= n; i++) {
        x[i] = a[i][n + 1] / a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %.3f\n", i, x[i]);
    }

    return 0;
}
