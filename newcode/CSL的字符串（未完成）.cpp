#include<iostream>
#include<list>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100005;
string s;
int flag[256];
struct node{
	int pos;
	char c;
};
list<int> li[256];
list<node> ans;
list<int>::iterator iter1;
list<node>::iterator iter2;
int main(){
	while(cin>>s){
		int len=s.length();
		for(int i=0;i<len;i++){
			flag[s[i]-0]++;
			li[s[i]-0].push_back(i);
		}
		for(int i=0;i<256;i++){
			if(flag[i]){
				if(ans.empty()){
					ans.push_back(node{*li[i].begin(),char(i)});
				}
				else{
					cout<<*(li[i].end()--);
					if(*(li[i].end()--)>(*(ans.end()--)).pos){//当前字符最后出现位置在答案最后字符的后面
						for(iter1=li[i].begin();iter1!=li[i].end();iter1++){
							if(*iter1>(*(ans.end()--)).pos){
								ans.push_back({*iter1,char(i)});
								break;
							}
						}
					}
					else{//在中间或最前
						if(*(li[i].end()--)<(*ans.begin()).pos){//最前
							ans.insert(ans.begin(),node{*(li[i].end()--),char(i)});
						}
						else{//中间
							for(iter2=ans.begin();iter2!=ans.end();iter2++){
								if(*(li[i].end()--)>(*iter2).pos&&*(li[i].end()--)<(*(iter2++)).pos){
									ans.insert(iter2,node{*(li[i].end()--),char(i)});
									break;
								}
								iter2--;
							}
						}
					}
				}
			}
		}
		for(iter2=ans.begin();iter2!=ans.end();iter2++){
			cout<<(*iter2).c;
		}
		cout<<endl;
	}
}
