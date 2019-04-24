#include<iostream>
using namespace std;
const int maxn=505,maxm=505;
int n,m,a[maxn],b[maxm],result[maxn+maxm];
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		cin>>b[i];
	}
	for(int i=0;i<=n+m;i++){
		for(int j=0;j<=i;j++){
			result[i]+=(a[j]*b[i-j]);
		}
	}
	cout<<result[0];
	for(int i=1;i<=n+m;i++){
		cout<<" "<<result[i];
	}
	cout<<endl;
}
