#include<bits/stdc++.h>
using namespace std;
const int maxn(305);
int t,n,d[maxn],ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>d[i];
		}
		sort(d,d+n);
		if(n%2){
			ans=d[n/2]*d[n/2];
		}
		else{
			ans=d[n/2]*d[n/2-1];
		}
		for(int i=0;i<n/2;i++){
			if(d[i]*d[n-1-i]!=ans){
				ans=-1;
				break;
			}
		}
	}
}
