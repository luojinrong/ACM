#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define per(i, a, b) for(int i=a; i<b; i++)
#define mem(a, b) memset(a, b, sizeof(a))

const int MAXN(1e3 + 7);
const ll INF(0x3f3f3f3f);
const double ESP(1e-9);
int N, M;
int mapp[MAXN][MAXN];
int valu[MAXN];
int vis[MAXN], sumv[MAXN], sumt[MAXN];
double mxp;

void dfs(int pos, double val, double tim) {
	per(i, 1, N + 1) {
		if (mapp[pos][i] < INF) {
			if (vis[i]) {
				//if(i==1) cout << mxp << " " << val << " " << tim << " " << mapp[pos][i] << endl;
				mxp = max(mxp, (val - sumv[i]) / (tim + mapp[pos][i] - sumt[i]));
			}
			else {
				vis[i] = 1;
				sumv[i] = val;
				sumt[i] = tim+mapp[pos][i];
				dfs(i, val + valu[i], tim + mapp[pos][i]);
				vis[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	mem(mapp, 0x3f);
	per(i, 1, N + 1) { cin >> valu[i]; }
	per(i, 1, M + 1) {
		int u, v, w;
		cin >> u >> v >> w;
		mapp[u][v] = min(mapp[u][v], w);
	}
	vis[1] = 1;
	dfs(1, valu[1], 0);
	if (mxp <= ESP) mxp = 0;
	cout << fixed << setprecision(2) << mxp << endl;

	return 0;
}