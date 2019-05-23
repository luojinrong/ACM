#include<bits/stdc++.h>
using namespace std;
const int maxn(2e5+5);
int n,a[maxn],ans,flag[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int id=1,tmp;
	while(id<=n){
		while(flag[ans+1]){
			ans++;
			tmp--;
		}
		if(a[id]>=ans+1){
			if(a[id]-ans-1>=ans+2){
				flag[ans++]=1;
				a[id]-=ans;
			}
			else{
				flag[a[id]]=1;
				tmp++;
				id++;
			}
		}
		else{
			id++;
		}
	}
	cout<<ans+tmp<<"\n";
}
