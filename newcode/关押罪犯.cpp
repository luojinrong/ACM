//head.cpp
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#include<string>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<set>


#define per(i,a,n) for (int i=a;i<n;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pI;
typedef vector<ll> vI;
const ll mod(1e9 + 7);
const ll INF(0x3f3f3f3f);
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// head

const int maxn=20005,maxm=100005;

class UnionFind {
private:
    int *parent;   // 标注当前元素的父节点的位置
    int *rank;     // 标注当前元素的层级数
    int size;       // 并查集中的元素个数

    //将父节点指向自身表示此为根结点，初始化层数1，所有元素独立成集合。
    void init() {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

public:
    UnionFind (int size){
        this->size = size;

        parent = new int[size];
        rank = new int[size];

        init();
    }
    //寻找父节点
    int find(int target) {
        if(target >= size)//数组越界
            return -1;
        if(target == parent[target])
            return target;
        return find(parent[target]);
    }
    //合并集合
    void get_together(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot)//本来就是同一个集合
            return;
        if(rank[pRoot] > rank[qRoot]) { // p 所在的树的高度比 q 所在树的高度高，这时应该让 q 的根节点元素连接到 p 的根节点元素
            parent[qRoot] = pRoot; // 此时树的高度不变
        } else if(rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot; // 此时树的高度不变
        } else {
            parent[pRoot] = qRoot; // 此时树的高度 +1
            rank[qRoot] += 1;
        }
    }
    // 如果两个节点的根节点一致则表示这两个节点是相连接的
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

};


struct Edge{
	int a,b,c;
}edges[maxm];

int cmp(struct Edge e1,struct Edge e2){
	return e1.c>e2.c;
}

int main(){
	UnionFind uf(maxn*2);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].c;
	}
	sort(edges,edges+M,cmp);
	for(int i=0;i<M;i++){
		int x=uf.find(edges[i].a),y=uf.find(edges[i].b);
		if(x==y){
			cout<<edges[i].c<<endl;
			return 0;
		}
		int xx=uf.find(edges[i].a+N),yy=uf.find(edges[i].b+N);
		uf.get_together(x,yy);
		uf.get_together(xx,y);
	}
	cout<<"0"<<endl;
	return 0;
}
