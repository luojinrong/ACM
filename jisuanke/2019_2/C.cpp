#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(1e3 + 5);
ll ans, T, n, tmp, flag[maxn], a[maxn], pos, f_ans, t_len;
struct value {
	ll pos, v;
	bool operator < (const value &a) const {
		return pos > a.pos;
	}
}t[maxn];
priority_queue<value> pq;
const ll mod(332748118);

int dp[maxn];
int path[maxn];//保存路径 
void print_path(int k)//递归打印路径 
{
	if (path[k] == k)
	{
		//cout << k << ' ';
		flag[k] = 1;
		return;
	}
	else print_path(path[k]);
	//cout << k << ' ';
	flag[k] = 1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n; int maxlen = 1, biao = 0;
		pos = 0;
		f_ans = 1;
		for (int i = 0; i < n; i++) {
			flag[i] = 0;
			cin >> a[i];
			dp[i] = 1;
			path[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				if (a[j] < a[i] && dp[i] < (dp[j] + 1))//DP核心代码 
				{
					dp[i] = dp[j] + 1;
					if (dp[i] > maxlen)maxlen = dp[i];
					path[i] = j;
					biao = i;
				}
		}
		t_len = n - maxlen;
		print_path(biao);
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0) {
				t[pos++] = value{ i,a[i] };
			}
		}
		for (int i = 0; i < pos - 1; i++) {
			if (t[i].v >= t[i + 1].v) {
				f_ans = 0;
				break;
			}
		}
		if (f_ans) {
			for (int i = 0; i < n; i++) {
				if (flag[i]) {
					if (i < t[0].pos&&a[i] < t[0].v) {
						t_len++;
						maxlen--;
					}
					else if (i > t[pos - 1].pos&&a[i] > t[0].v) {
						t_len++;
						maxlen--;
					}
					else {
						for (int j = 0; j < pos - 1; j++) {
							if (i > t[j].pos&&i<t[j + 1].pos&&a[i]>t[j].v&&a[i] < t[j + 1].v) {
								t_len++;
								maxlen--;
							}
						}
					}
					if (abs(t_len - maxlen) == 0 || abs(t_len - maxlen) == 1) {
						break;
					}
				}
			}
		}
		if (f_ans) {
			ans = abs(t_len - maxlen);
		}
		else {
			ans = -1;
		}
		cout << ans << "\n";
	}
}