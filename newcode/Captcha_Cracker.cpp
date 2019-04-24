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

int main(){
	int T;
	char s[100005];
	cin>>T;
	for(;T;T--){
		cin>>s;
		for(int i=0;s[i];i++){
			if((s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')||(s[i]=='2')){
				cout<<'2';
			}
			else if((s[i]=='z'&&s[i+1]=='e'&&s[i+2]=='r'&&s[i+3]=='o')||(s[i]=='0')){
				cout<<'0';
			}
			else if((s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='r')||(s[i]=='4')){
				cout<<'4';
			}
			else if((s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='x')||(s[i]=='6')){
				cout<<'6';
			}
			else if((s[i]=='n'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='e')||(s[i]=='9')){
				cout<<'9';
			}
		}
		cout<<endl;
	}
}
