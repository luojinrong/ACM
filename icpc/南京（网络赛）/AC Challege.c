#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) (a)>(b)?(a):(b)
typedef long long ll;
int n,s_0[20],s0,time;
struct simple_P{
	int a, b, pn;
};
struct problem {
	int a,b,s,p[20],flag;
}ps[20];
ll sy,m;

int comp(const void*a, const void*b) {
	return ((struct simple_P*)a)->a - ((struct simple_P*)b)->a;
}

void dfs(ll sy, int time) {
	struct simple_P sp[20];
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (ps[i].flag == 0 && ps[i].s == 0) {
			sp[t].a = ps[i].a;
			sp[t].b = ps[i].b;
			sp[t++].pn = i;
		}
	}
	qsort(sp, t, sizeof(struct simple_P), comp);
	for (int i = 0; i < t; i++) {
		int ji[20] = { 0 };
		ps[sp[i].pn].flag = 1;
		m = max(m, sy + sp[i].a*time + sp[i].b);
		for (int j = 0; j < n; j++) {
			if (ps[j].flag == 0 && ps[j].p[sp[i].pn] == 1) {
				ps[j].p[sp[i].pn] = 0;
				ps[j].s--;
				if (ps[j].s == 0) {
					s0++;
					s_0[j] = 1;
				}
			}
		}
		dfs(sy + sp[i].a*time + sp[i].b, time + 1);
		for (int j = 0; j < n; j++) {
			if (ji[j]) {
				ps[j].p[sp[i].pn] = 1;
				if (ps[j].s == 0) {
					s0--;
					s_0[j] = 0;
				}
				ps[j].s++;
			}
		}
		ps[sp[i].pn].flag = 0;

	}
}

int main() {
	while (~scanf("%d", &n)) {
		memset(s_0, 0, sizeof(s_0));
		s0 = time = 0; sy = m = 0;
		for (int i = 0; i < n; i++) {
			ps[i].flag = 0;
			scanf("%d%d%d", &ps[i].a, &ps[i].b, &ps[i].s);
			for (int j = 0; j < ps[i].s; j++) {
				int t_p;
				scanf("%d", &t_p);
				ps[i].p[t_p - 1] = 1;
			}
			if (ps[i].s == 0 && ps[i].flag == 0) {
				s_0[i] = 1;
				s0++;
			}
		}
		dfs(0, 1);
		printf("%lld\n", m);
	}
}