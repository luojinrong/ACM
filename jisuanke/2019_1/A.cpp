#include<bits/stdc++.h>
using namespace std;
const int maxn(5e3+5);
int n,to[maxn],max1,max2,ans,t1,t2;
vector<int> v[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int tmp_f,tmp_t;
		cin>>tmp_f>>tmp_t;
		v[tmp_f].push_back(tmp_t);
		to[tmp_f]++;
	}
	if(n==2){
		ans=0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max1=to[i]+to[j]+1;
				for(int k=0;k<v[i].size();k++){
					if(v[i][k]==j){
						max1--;
					}
				}
				for(int k=0;k<v[j].size();k++){
					if(v[j][k]==i){
						max1--;
					}
				}
				if(i==1){
					max1--;
				}
				if(max1>ans){
					ans=max1;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
