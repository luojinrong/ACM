#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, m, **score, *ave;

int main() {
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		score = (int**)malloc(sizeof(int*)*n);
		ave = (int*)malloc(sizeof(int)*m);
		memset(ave, 0, sizeof(int)*m);
		for (int i = 0; i < n; i++) {
			score[i] = (int*)malloc(sizeof(int)*m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &score[i][j]);
				ave[j] += score[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			printf("%.2f%c", ave[i]/(n+0.0), " \n"[i==m-1]);
		}
	}
}