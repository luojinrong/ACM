#include<stdio.h>
#include<math.h>
typedef long long ll;
int T;
ll p;
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%lld", &p);
		for (ll i = 0; i < p; i++) {
			for (ll j = 0; j < p; j++) {
				printf("%d%c", 2, " \n"[j == p - 1]);
			}
		}
		for (ll i = 0; i < p; i++) {
			printf("0%c", " \n"[i == p - 1]);
		}
		for (ll i = 1; i < p; i++) {
			for (ll j = 0; j < p; j++) {
				printf("%lld%c", i == p - 1 ? 1 : i + 1, " \n"[j == p - 1]);
			}
		}
	}
}