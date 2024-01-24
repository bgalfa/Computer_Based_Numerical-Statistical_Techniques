#include <stdio.h>
#include <math.h>
#include<stdlib.h>
void print_mat(float **aug, int n) {
    printf("Matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f  ", aug[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
   printf("Name:BHAVYA GUPTA\nUni Roll No.:2018764\nClass Roll No.:18\n");


    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);
    float** aug = (float*)malloc(n * sizeof(float));

    for(int i=0;i<n;i++)
    {
      aug[i] = (float*)malloc((n + 1) * sizeof(float));
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter the coefficients and constant value for row %d: ", i + 1);
        for (int j = 0; j <= n; j++) {
            scanf("%f", &aug[i][j]);
        }
    }
    printf("INPUT\n");
    print_mat(aug, n);

    // Forward elimination (Gaussian Elimination)
    for (int i = 0; i < n; i++) {
        float divide_by = aug[i][i];
        for (int j = 0; j <= n; j++) {
            aug[i][j] /= divide_by;
        }

        for (int k = i + 1; k < n; k++) {
            float mul = aug[k][i];
            if (mul == 0) {
                continue;
            } else {
                for (int j = 0; j <= n; j++) {
                    aug[k][j] = aug[k][j] - aug[i][j] * mul;
                }
            }
        }
        
    }

    printf("AFTER FINAL ROW OPERATION :\n");
    print_mat(aug, n);
    // Back-substitution to find variable values
    float x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = aug[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= aug[i][j] * x[j];
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}