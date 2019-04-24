//带优先级的二分匹配
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#define INF 0x3fffffff
using namespace std;

const int N = 100005;//最大节点对数，根据题目修改
int n, wCount, m, w_flag[2], m_flag[2], f, W_1arr, W_0arr;//n表示匹配对数，wCount表示当前匹配对数
struct PARTNER {
	int current;//当前匹配目标的下标，这是在W[]或M[]中的下标，若单身则为-1
	int flag;
	int height;
}M[N], W[N];

bool comp(const PARTNER& a, const PARTNER& b) {
	return a.flag == b.flag ? a.height < b.height : a.flag < b.flag;
}

template<typename t>
inline bool scan_d(t &x) {
	char c;
	int sgn;
	if (c = getchar(), c == EOF) {
		return 0;
	}
	while (c != '-' && (c<'0' || c>'9')) {
		c = getchar();
	}
	sgn = (c == '-') ? -1 : 1;
	x = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
	}
	x *= sgn;
	return 1;
}

//int GetFreeMan(int now) {//获取一个单身男性下标，若不存在单身男性则返回-1
//	for (int i = now; i<n; i++) {
//		if (M[i].current == -1) {
//			return i;
//		}
//	}
//	return -1;
//}

int GEtWomanPos(int Mpos) {
	if (M[Mpos].flag == 0) {//喜欢比自己矮，从高到矮
		if (W_0arr == -2) {
			W_0arr = m-1;
		}
		else if (W_0arr < w_flag[0]) {
			return -1;
		}
		else {
			W_0arr--;
		}
		if (W_0arr < w_flag[0]) {
			return -1;
		}
		return W_0arr;
	}
	else {//喜欢比自己高，从矮到高
		if (W_1arr == -2) {
			W_1arr = 0;
		}
		else if (W_1arr >= w_flag[0]) {
			return -1;
		}
		else {
			W_1arr++;
		}
		if (W_1arr >= w_flag[0]) {
			return -1;
		}
		return W_1arr;
	}
}

void gale_shapley() {//算法部分
	W_1arr = W_0arr = -2;
	for (int mid = m_flag[0]-1; mid >= 0; ) {//喜欢比自己矮，从高到矮
		int wid = GEtWomanPos(mid);//获取该单身男性下一个追求目标
		if (wid == -1) {
			M[mid].current = -2;
			break;
		}
		if (W[wid].current == -1 && M[mid].flag == 0 && M[mid].height > W[wid].height) {//下一个追求目标单身，直接在一起
			W[wid].current = mid;
			M[mid].current = wid;
			mid--;
			wCount++;
		}
		else if (W[wid].current == -1 && M[mid].flag == 1 && M[mid].height < W[wid].height) {
			W[wid].current = mid;
			M[mid].current = wid;
			mid--;
			wCount++;
		}
	}
	for (int mid = m_flag[0]; mid < n;) {//喜欢比自己高，从矮到高
		int wid = GEtWomanPos(mid);//获取该单身男性下一个追求目标
		if (wid == -1) {
			M[mid].current = -2;
			break;
		}
		if (W[wid].current == -1 && M[mid].flag == 0 && M[mid].height > W[wid].height) {//下一个追求目标单身，直接在一起
			W[wid].current = mid;
			M[mid].current = wid;
			mid++;
			wCount++;
		}
		else if (W[wid].current == -1 && M[mid].flag == 1 && M[mid].height < W[wid].height) {
			W[wid].current = mid;
			M[mid].current = wid;
			mid++;
			wCount++;
		}
	}
}

void AddMan(int p) {//创建一个男性
	M[p].current = -1;//令单身
	scan_d<int>(M[p].height);
}

void AddWoman(int p) {//创建一个女性
	W[p].current = -1;//令单身
	scan_d<int>(W[p].height);
}




int main() {
	//ios_base::sync_with_stdio(false);
	int T;
	while (scan_d<int>(T)) {
		while (T--) {
			scan_d<int>(n);
			scan_d<int>(m);
			wCount = m_flag[0] = m_flag[1] = w_flag[0] = w_flag[1] = 0;
			for (int i = 0; i < n; i++) {
				AddMan(i);
			}
			for (int i = 0; i < m; i++) {
				AddWoman(i);
			}
			for (int i = 0; i < n; i++) {
				scan_d<int>(M[i].flag);
				m_flag[M[i].flag]++;
			}
			for (int i = 0; i < m; i++) {
				scan_d<int>(W[i].flag);
				w_flag[W[i].flag]++;
			}
			sort(M, M + n, comp);
			sort(W, W + m, comp);
			gale_shapley();
#if 0
			for (int i = 0; i<n; i++) {
				cout << i <<":"<<M[i].height<<  "\t--\t" << M[i].current<<":"<<W[M[i].current].height << endl;
			}
			cout << "total : " << wCount << endl;
#endif
			cout << wCount << endl;
		}
	}
}
