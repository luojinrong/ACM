/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
0 1 0 1 0 0 0 1 1  1  0  1  0  0  0  1  1  1  1  1
0 1 1 2 2 2 2 3 4  5  5  6  6  6  6  7  8  9 10 11

2 12
10  1100

1 2 3 4 5  6  7  8
0 1 1 4 5 16 22 64
n%2==0 2^(n-2)
n%2==1 (2^(n-1)-C(n-1,(n-1)/2))/2
*/
#include<iostream>
using namespace std;
int ans, a, b, bits_a, bits_b, ones_a, ones_b;

int C(int n, int m) {
	int ans = 1;
	for (int i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i; //注意一定先乘再除
	}
	return ans;
}

int cal(int n) {
	if (n % 2 == 0) {
		return pow(2, n - 2);
	}
	else {
		return ((pow(2, n - 1) - C(n - 1, (n - 1) / 2)) / 2);
	}
}

int upper() {
	int tmp_a = a, num=1;
	char str_a[50];
	while (tmp_a) {
		if (tmp_a % 2) {
			ones_a++;
		}
		if (tmp_a) {
			str_a[bits_a++] = tmp_a % 2+'0';
			str_a[bits_a] = 0;
			tmp_a >>= 1;
		}
	}
	if (ones_a > bits_a / 2) {
		return 0;
	}
	else {
		int ones = 0;
		for (int i = bits_a - 1; i >= 0; i--) {
			if (str_a[i] == '0') {
				if (ones + 1 > bits_a / 2) {
					break;
				}
				else {
					for (int j = 0; ones + 1 + j <= bits_a / 2; j++) {
						num += C(i, j);
					}
				}
			}
			else {
				ones++;
			}
		}
		return num;
	}
}

int lower() {
	int tmp_b = b, num=0;
	char str_b[50];
	while (tmp_b) {
		if (tmp_b % 2) {
			ones_b++;
		}
		if (tmp_b) {
			str_b[bits_b++] = tmp_b % 2+'0';
			str_b[bits_b] = 0;
			tmp_b >>= 1;
		}
	}
	if (ones_b <= bits_b / 2) {
		num++;
	}
	int ones = ones_b;
	for (int i = 0; i <= bits_b - 2; i++) {
		if (str_b[i] == '1') {
			ones -= 1;
			if (ones <= bits_b / 2) {
				for (int j = 0; ones + j <= bits_b / 2; j++) {
					num += C(i, j);
				}
			}
			else {
				continue;
			}
		}
	}
	return num;
}

int main() {
	cin >> a >> b;
	ans = upper() + lower();
	if (bits_a == bits_b) {
		ans -= cal(bits_a);
	}
	for (int i = bits_a + 1; i < bits_b; i++) {
		ans += cal(i);
	}
	cout << ans << endl;
}