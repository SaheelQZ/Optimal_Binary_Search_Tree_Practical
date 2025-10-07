#include<stdio.h>
#include<limits.h>

#define MAX 50

void OptimalBST(float p[], float q[], int n){
    float w[MAX][MAX], c[MAX][MAX];
    int r[MAX][MAX];

    for(int i = 0; i <= n; i++){
        w[i][i] = q[i];
        c[i][i] = 0;
    }

    for(int m = 1; m <= n; m++){
        for(int i = 0; i <= n - m; i++){
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            float min = INT_MAX;
            int kmin = 0;

            for(int k = i + 1; k <= j; k++){
                float val = c[i][k - 1] + c[k][j];
                if(val < min){
                    min = val;
                    kmin = k;
                }
            }

            c[i][j] = w[i][j] + min;
            r[i][j] = kmin;
        }
    }

    printf("\nMinimum Expected Coat of OBST: %.4f",c[0][n]);
}

int main(){
    int n;
    printf("Enter number of keys: ");
    scanf("%d",&n);

    int keys[MAX];
    float p[MAX], q[MAX];

    printf("Enter %d sorted keys: ",n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&keys[i]);

    printf("Enter %d probabilities for successful searches (p[i]): ",n);
    for(int i = 1; i <= n; i++)
        scanf("%f",&p[i]);

    printf("Enter %d probabilities of unsuccessful searches (q[i]): ",n + 1);
    for(int i = 0; i <= n; i++)
        scanf("%f",&q[i]);

    OptimalBST(p, q, n);
    return 0;
}