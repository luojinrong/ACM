#include <bits/stdc++.h>
using namespace std;
#define per(i,a,n) for (int i=a;i<n;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> PI;
const ll mod = 1e9 + 7;
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// head

char n[10], minn[10], maxn[10];
ll _, k, k1, k2, len, changnum;
int chang[10];

int cmp1(char a, char b) {
	return a < b;
}
int cmp2(char a, char b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	for (cin >> _; _; _--) {
		cin >> n >> k;
		len = strlen(n);
		k1 = k2 = k = min(len - 1, k);
		per(i, 0, len+1) {
			minn[i] = maxn[i] = n[i];
		}
		per(i, 0, k1) {
			int mini = 10, minidex = -1;
			changnum = 1;
			rep(j, i, len) {
				if (minn[j] - '0' <= mini) {
					if (i == 0 && minn[j] == '0') {
						continue;
					}
					if (minn[j] - '0' == mini) {
						chang[changnum++] = j;
					}
					else {
						changnum = 1;
						chang[0] = j;
						mini = minn[j] - '0';
						minidex = j;
					}
				}
			}
			if (mini != minn[i]-'0') {
				if (changnum > 1 && k1 - i > 1 && i != 0) {
					int mmm = min(changnum, k1 - i);
					per(ff, i, i + mmm) {
						if (minn[ff] - '0' == mini) {
							mmm++;
						}
					}
					sort(minn + i, minn + i + mmm, cmp2);
					per(f, 0, mmm) {
						char t = minn[i + f];
						minn[i + f] = minn[chang[f]];
						minn[chang[f]] = t;
					}
					k1 -= changnum - 1;
				}
				else {
					minn[minidex] = minn[i];
					minn[i] = mini + '0';
				}
			}
			else {
				k1++;
			}
			if (i >= len - 1) {
				break;
			}
		}
		per(i, 0, k2) {
			int maxi = -1, maxidex = -1;
			changnum = 1;
			rep(j, i, len) {
				if (maxn[j] - '0' >= maxi) {
					if (maxn[j] - '0' == maxi) {
						chang[changnum++] = j;
					}
					else {
						changnum = 1;
						chang[0] = j;
						maxi = maxn[j] - '0';
						maxidex = j;
					}
				}
			}
			if (maxi != maxn[i]-'0') {
				if (changnum > 1 && k2 - i > 1) {
					int mmm = min(changnum, k2 - i);
					per(ff, i, i + mmm) {
						if (maxn[ff] - '0' == maxi) {
							mmm++;
						}
					}
					sort(maxn + i, maxn + i + mmm, cmp1);
					per(f, 0, mmm) {
						char t = maxn[i + f];
						maxn[i + f] = maxn[chang[f]];
						maxn[chang[f]] = t;
					}
					k2 -= changnum - 1;
				}
				else {
					maxn[maxidex] = maxn[i];
					maxn[i] = maxi + '0';
				}
			}
			else {
				k2++;
			}
			if (i >= len - 1) {
				break;
			}
		}
		cout << minn << ' ' << maxn << endl;
	}
}
