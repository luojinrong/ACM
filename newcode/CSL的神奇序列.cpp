#include<iostream>

using namespace std;

typedef long long ll;
ll w,n,q;
const ll maxn=1000005;
ll array[maxn];
ll mod=998244353;

void pre(){
	array[1]=1;
	for(int i=2;i<maxn;i++){
		array[i]=(array[i-1]*(i*2-1))%mod;
	}
}

int main(){
	pre();
	while(cin>>w>>q){
		for(ll i=0;i<q;i++){
			ll query;
			cin>>query;
			cout<<array[query]*w%mod<<endl;
		}
	}
}
