#include<bits/stdc++.h>
using namespace std;
const int maxn(1e5+5);
string s;
int T,n,x,y,ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>y;
	cin>>s;
	for(int i=0;i<y;i++){
		if(s[n-1-i]=='1'){
			ans++;
		}
	}
	if(s[n-1-y]=='0'){
		ans++;
	}
	for(int i=y+1;i<x;i++){
		if(s[n-1-i]=='1'){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
