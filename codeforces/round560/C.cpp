#include<bits/stdc++.h>
using namespace std;
const int maxn(2e5+5);
string s;
char tmp;
int n,ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(s.size()%2==0){
			s.append(&tmp);
		}
		else{
			if(tmp==s[s.size()-1]){
				ans++;
			}
			else{
				s.append(&tmp);
			}
		}
	}
	if(s.size()%2){
		s.pop_back();
		ans++;
	}
	cout<<ans<<"\n"<<s<<"\n";
}
