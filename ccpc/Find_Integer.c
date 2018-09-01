#include<stdio.h>
int n, a, b, c;
int main() {
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &a);
		if (n == 0) {
			printf("-1 -1\n");
		}
		else if (n == 1) {
			printf("1 %d\n", a + 1);
		}
		else if (n == 2) {
			int mul = a * a;
			if (mul & 1) {
				printf("%d %d\n", mul / 2, mul / 2 + 1);
			}
			else {
				b = (mul - 4) / 4;
				c = b + 2;
				printf("%d %d\n", b, c);
			}
		}
		else {
			printf("-1 -1\n");
		}
	}
}