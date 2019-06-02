#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(1e5 + 5);
ll ans, T, n, tmp, flag;
vector<ll> v[2];
const ll mod(332748118);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		v[0].clear();
		v[1].clear();
		flag = 1;
		cin >> n;
		while (n--) {
			cin >> tmp;
			if (flag) {
				if (v[0].size() == 0) {
					v[0].push_back(tmp);
				}
				else if (tmp > v[0].back()) {
					v[0].push_back(tmp);
				}
				else if (v[1].size() == 0) {
					v[1].push_back(tmp);
				}
				else if (tmp > v[1].back()) {
					v[1].push_back(tmp);
				}
				else {
					flag = 0;
				}
			}
		}
		if (flag) {
			ans = abs(int(v[1].size() - v[0].size()));
		}
		else {
			ans = -1;
		}
		cout << ans << "\n";
	}
}