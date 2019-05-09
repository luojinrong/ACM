#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f,maxn=15;
int pos[maxn],ans,vis[maxn];

void dfs(int num,int step){
	if(step>ans){
		return;
	}
	if(num==10){
		ans=step;
		return;
	}
	else{
		for(int i=1;i<=10;i++){
			if(!vis[i]){
				for(int j=i+1;j<=10;j++){
					if(!vis[j]){
						vis[i]=1;
						dfs(num+1,step+abs(pos[i]-pos[j]));
						break;
					}
				}
				vis[i]=0;
			}
		}
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		ans=INF;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<10;i++){
			int tmp;
			cin>>tmp;
			pos[tmp]=i;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
}
