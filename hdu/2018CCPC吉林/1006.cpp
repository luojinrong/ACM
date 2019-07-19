#include<bits/stdc++.h>
using namespace std;
int T,ans,rad,n;
int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>rad;
			if(rad>2){
				ans^=rad-2;
			}
		}
		cout<<"Case "<<t<<": "<<ans<<endl;
	}
}
