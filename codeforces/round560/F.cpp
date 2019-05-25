#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(2e5+5);
ll order[maxn],n,m,ans,ordered[maxn],total,buy;
vector<ll> v[maxn<<1];//因为最后答案的最大值可以到total的两倍，所以要开两倍的空间，否则会RE

bool check(ll money){
	buy=0;//已买数量
	ll left=0;//剩余的钱
	for(ll i=1;i<=n;i++){
		ordered[i]=order[i];
	}
	for(ll i=money;i>0;i--){//从后往前遍历，贪心，越后面买越好
		for(ll j=0;j<v[i].size();j++){
			if(ordered[v[i][j]]&&money){
				ll tmp=min(ordered[v[i][j]],money);
				ordered[v[i][j]]-=tmp;
				money-=tmp;
				buy+=tmp;
			}
		}
		if(money>=i){//当天赚的钱没有花掉
			left++;//加到剩余的钱里面，因为不能花未来赚到的钱
			money--;
		}
	}
	return left/2>=total-buy;//剩余的钱能不能买到还没买的东西
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>order[i];
		total+=order[i];//要买的总数
	}
	for(ll i=0;i<m;i++){
		ll tmp_d,tmp_t;
		cin>>tmp_d>>tmp_t;
		v[tmp_d].push_back(tmp_t);
	}
	ll l=total,r=total*2,mid;
	while(l<=r){//二分
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
