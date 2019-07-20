#include<bits/stdc++.h>
using namespace std;
const int maxn(1e4+5);
queue<int>ax,ay,as;
int x,y,n,a,b,mapp[1005][1005],ans=maxn*maxn;
void bfs(int px,int py,int step){
	if(!mapp[px+1][py]){
		mapp[px+1][py]=1;
		ax.push(px+1),ay.push(py),as.push(step+1);
	}
	if(!mapp[px-1][py]){
		mapp[px-1][py]=1;
		ax.push(px-1),ay.push(py),as.push(step+1);
	}
	if(!mapp[px][py+1]){
		mapp[px][py+1]=1;
		ax.push(px),ay.push(py+1),as.push(step+1);
	}
	if(!mapp[px][py-1]){
		mapp[px][py-1]=1;
		ax.push(px),ay.push(py-1),as.push(step+1);
	}
}
int main(){
    cin>>x>>y>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mapp[a+501][b+501]=1;
    }
    x+=501,y+=501;
	mapp[501][501]=1;
	ax.push(501);
	ay.push(501);
	as.push(0);
	while(!ax.empty()){
		int nx=ax.front(),ny=ay.front(),ns=as.front();
		ax.pop(),ay.pop(),as.pop();
		if(nx==x&&ny==y){
			ans=ns;
			break;
		}
		bfs(nx,ny,ns);
	}
    cout<<ans<<endl;
}
