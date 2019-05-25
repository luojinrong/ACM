//Longest Common Substring
#include<bits/stdc++.h>
using namespace std;
string s1, s2;
const int maxn = 1e4 + 5;
int dp[maxn][maxn], maxlen;
int main() {
	while (cin >> s1 >> s2) {
		int len1 = s1.length(), len2 = s2.length();
		maxlen = 0;
		for (int i = 0; i <= len1; i++) {
			dp[i][0] = 0;
		}
		for (int i = 0; i <= len2; i++) {
			dp[0][i] = 0;
		}
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else {
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
		cout << dp[len1][len2] << "\n";
	}
}