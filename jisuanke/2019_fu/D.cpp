#include<bits/stdc++.h>
using namespace std;
const int maxn(5e6+5);
char s[maxn];
vector<char> ans;
int k,ans_p[maxn],len;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>k;
	for(int i=0;i<k;i++){
		ans_p[i]=i;
	}
	len=strlen(s);
//	for(int i=0;i<len;i++){
//		for(int j=(len-i>k?0:(k-len+i));j<k;j++){
//			if(s[i]<s[ans_p[j]]){
//				if(i>ans_p[j]){
//					for(int x=0;x<k-j;x++){
//						ans_p[j+x]=i+x;
//					}
//				}
//				else{
//					break;
//				}
//			}
//		}
//	}
	for(int i=0;i<len;i++){
		if(ans.empty()){
			ans.push_back(s[i]);
		}
		else{
			if(s[i]>=ans.back()&&(int)ans.size()<k){
				ans.push_back(s[i]);
			}
			else if(s[i]<ans.back()){
				while(s[i]<ans.back()){
					if((len-i)>(k-(int)ans.size())){
						ans.pop_back();
					}
					else{
						break;
					}
				}
				ans.push_back(s[i]);
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<ans[i];
	}
	cout<<"\n";
}
