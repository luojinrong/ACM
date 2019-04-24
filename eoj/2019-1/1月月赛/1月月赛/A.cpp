#include<iostream>
using namespace std;

const int maxn = 1e6 + 5;
int n, c_or_d, a[maxn], now_d, now_c, down_d, down_c, timee, s, zero;
char tm;

void cal() {
	while (s) {//s为交战次数，未发生交战则结束
		s = 0; zero = 0;
		if (a[0]) {
			c_or_d = (tm != 'C');
		}
		else {
			c_or_d = 0;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] && (zero % 2 == 0)) {//遇到下一个城邦
				zero = 0;
				if (c_or_d) {//属于c
					if (now_d&&now_c) {//当前都有城池
						now_d >= now_c ? (a[down_d]++, a[down_c]--) : (a[down_d]--, a[down_c]++);
						now_d = 0;
						now_c = 0;
						s++;
					}
					//now_d = 0;//d城池归零
					down_d = i;//记录下一个d城邦下标
				}
				else {//属于d
					now_c = 0;//c城池清零
					down_c = i;//记录下一个c城邦下标
				}
				c_or_d ^= 1;
			}
			else if(now_d||now_c) {
				zero++;
			}
			if (c_or_d) {
				now_c += a[i];
			}
			else {
				now_d += a[i];
			}
		}
		if (c_or_d&&now_d&&now_c) {
			now_d >= now_c ? (a[down_d]++, a[down_c]--) : (a[down_d]--, a[down_c]++);
			now_d = 0;
			now_c = 0;
			s++;
		}
		if (s > 0) {
			timee++;
		}
	}
}

int main() {
	int T;
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n;
		cin >> tm;
		//c_or_d = (tm != 'C');
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		s = 1; now_d = 0; now_c = 0; down_c = 0; down_d = 0; timee = 0;
		cal();
		cout << timee << " " << now_d << " " << now_c << " " << endl;
	}
}