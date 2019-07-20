#include<bits/stdc++.h>
using namespace std;
const int maxn(1e5+5);
int T,n,k[maxn],stn,ans[maxn];
set<int> st[maxn];
map<int,int>mp;
map<int,int>::iterator mm;
int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		stn=0;
		mp.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			st[i].clear();
			ans[i]=0;
			cin>>k[i];
			if(mp.find(k[i])==mp.end()){
				mp[k[i]]=stn++;
			}
			st[mp[k[i]]].insert(i);
		}
		int now_find=1,now_need=1;//初始只需要找1个1
		for(mm=mp.begin();mm!=mp.end();mm++){//遍历map
			if(mm->first!=now_find){//map当前遍历到的值即为要找的
				now_need*=pow(2,mm->first-now_find);
				now_find=mm->first;
			}
			if(!st[mm->second].empty()){//遍历对应的set
				set<int>::iterator ss;
				for(ss=st[mm->second].begin();ss!=st[mm->second].end()&&now_need;ss++){
					ans[*ss]=1;
					now_need--;
					st[mm->second].erase(ss);
				}
			}
			if(now_need==0){
				break;
			}
		}
		if(now_need==0){
			now_find=1,now_need=1;
			for(mm=mp.begin();mm!=mp.end();mm++){//遍历map
				if(mm->first!=now_find){//map当前遍历到的值即为要找的
					now_need*=pow(2,mm->first-now_find);
					now_find=mm->first;
				}
				if(!st[mm->second].empty()){//遍历对应的set
					set<int>::iterator ss;
					for(ss=st[mm->second].begin();ss!=st[mm->second].end()&&now_need;ss++){
						now_need--;
						st[mm->second].erase(ss);
					}
				}
				if(now_need==0){
					break;
				}
			}
		}
		if(now_need){
			cout<<"Case "<<t<<": NO"<<endl;
		}else{
			cout<<"Case "<<t<<": YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
}
