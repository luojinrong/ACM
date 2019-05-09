#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans[maxn],pos,arrive[maxn];

void Left_to_Right(int level,int start);
void Left_to_Up(int level,int start);
void Up_to_right(int level,int start);

int get_level(int num){
	int level=1;
	while(num!=1&&arrive[num/2]==0){
		num=num/2;
		level++;
	}
	return level;
}

int qpow(int a,int b){
	int ans=1,tmp=a;
	while(b){
		if(b&1){
			ans*=tmp;
		}
		tmp*=tmp;
		b=b>>1;
	}
	return ans;
}

void Left_to_Right(int level,int start){
	if(level==1){
		ans[pos++]=start;
	}
	else if(level==2){
		ans[pos++]=start;
		ans[pos++]=start/2;
		ans[pos++]=start-1;
		arrive[start]=arrive[start/2]=arrive[start-1]=1;
	}
	else{
		Left_to_Up(level-1,start);
		int root=start,l=0;
		while(l<level-1){
			root/=2;
			l++;
		}
		ans[pos++]=root;
		Up_to_right(level-1,root*2);
	}
}

void Left_to_Up(int level,int start){
	if(level==2){
		ans[pos++]=start;
		ans[pos++]=start-1;
		ans[pos++]=start/2;
		arrive[start]=arrive[start/2]=arrive[start-1]=1;
	}
	else{
		Left_to_Right(level-1,start);
		Left_to_Up(level-1,start-qpow(2,level-2));
		int root=start,l=0;
		while(l<level-1){
			root/=2;
			l++;
		}
		ans[pos++]=root;
	}
}

void Up_to_right(int level,int start){
	if(level==2){
		ans[pos++]=start;
		ans[pos++]=start*2+1;
		ans[pos++]=start*2;
		arrive[start]=arrive[start*2+1]=arrive[start*2]=1;
	}
	else{
		ans[pos++]=start;
		Up_to_right(level-1,start*2+1);
		int tmp=start*2,l=0;
		while(l<level-2){
			tmp=tmp*2+1;
			l++;
		}
		Left_to_Right(level-1,tmp);
	}
}

void pre(int num){
	arrive[num]=1;
	if(num==1){
		ans[pos++]=1;
		return;
	}
	pre(num/2);
	ans[pos++]=num;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<"1\n";
		}
		else{
			pos=0;
			for(int i=1;i<=n;i++){
				arrive[i]=0;
			}
			pre(n);
			while(!arrive[ans[pos-1]-1]){
				Left_to_Right(get_level(ans[pos-1]-1),ans[pos-1]-1);
			}
			for(int i=0;i<n;i++){
				cout<<ans[i]<<" \n"[i==n-1];
			}
		}
	}
}
