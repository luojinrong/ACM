#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define eps 1e-5
int N, M, K;

int main() {
	while (scanf("%d%d%d", &N, &M, &K) != EOF) {
		int i, j;
		double p1, p2, p3, p4, **dp = (double**)malloc(sizeof(double*)*(N + 1)), *C = (double*)malloc(sizeof(double)*(N + 1));
		for (i = 0; i < N + 1; i++) {
			dp[i] = (double*)malloc(sizeof(double)*(N + 1));
		}
		scanf("%lf%lf%lf%lf", &p1, &p2, &p3, &p4);
		if (p4 < eps) {
			printf("0.00000\n");
			continue;
		}
		double p21 = p2 / (1 - p1), p31 = p3 / (1 - p1), p41 = p4 / (1 - p1);
		//printf("%.5lf %.5lf %.5lf\n", p21, p31, p41);
		dp[1][1] = p4 / (1 - p1 - p2);
		//printf("%.5lf %.5lf ", dp[1][1], p41 / (1 - p21));
		for (i = 2; i <= N; i++) {
			C[i] = 0;
			for (j = 2; j <= i; j++) {
				C[i] += p31 * pow(p21, i-j)*dp[i - 1][j-1];
				if (j < K + 1) {
					C[i] += p41 * pow(p21, i-j);
				}
			}
			dp[i][i] = (C[i] + p41 * pow(p21, i - 1)) / (1 - pow(p21, i));
			dp[i][1] = p21 * dp[i][i] + p41;
			for (j = 2; j < i; j++) {
				dp[i][j] = p21 * dp[i][j - 1] + p31 * dp[i - 1][j - 1];
				if (j <= K) {
					dp[i][j] += p41;
				}
			}
		}
		printf("%.5lf\n", dp[N][M]);
		free(C);
		for (i = 0; i < N + 1; i++) {
			free(dp[i]);
		}
		free(dp);
	}
}
