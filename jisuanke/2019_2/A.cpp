#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, l, r, ans;
const ll mod(332748118);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	l = (((a + c - 1)%mod + (a + d - 1)%mod)*((d - c + 1)%mod)) / 2;
	r = (((b + c - 1)%mod + (b + d - 1)%mod)*((d - c + 1)%mod)) / 2;
	ans = ((l%mod + r % mod) % mod)*((b - a + 1) % mod) % mod;
	cout << ans << "\n";
}