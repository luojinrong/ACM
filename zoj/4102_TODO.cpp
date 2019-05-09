#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;

int a[maxn],b[maxn],c[maxn],mark[maxn],n,pre,nextt,flag;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		flag=1;
		for(int i=0;i<n;i++){
			mark[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
			mark[a[i]]++;
			if(mark[a[i]]>n/2){
				flag=0;
			}
			b[i]=a[i];
		}
		if(flag){
			sort(b,b+n);
			for(int i=0;i<n;i++){
				c[i]=b[i];
			}
			for(int i=0;i<n;){
				if(i==0){
					pre=-1;
				}
				else{
					pre=i-1;
				}
				if(i+mark[c[i]]>=n){
					nextt=-1;
				}
				else{
					nextt=i+mark[c[i]];
				}
				for(int j=0;j<mark[c[i]];j++){
					if(b[i+j]==a[i+j]){
						if(nextt!=-1){
							swap(b[i+j],b[nextt++]);
							if(nextt>=n){
								nextt=-1;
							}
						}
						else if(pre!=-1){
							swap(b[i+j],b[pre--]);
							if(pre<0){
								pre=-1;
							}
						}
					}
				}
				i=i+mark[c[i]];
			}
		}
		if(flag){
			for(int i=0;i<n;i++){
				cout<<b[i]<<" \n"[i==n-1];
			}
		}
		else{
			cout<<"Impossible\n";
		}
	}
}
