#include<bits/stdc++.h>
using namespace std;

bool legal(string s){
	vector<char> v;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='('){
			v.push_back(s[i]);
		}
		else{
			if(v.size()){
				v.pop_back();
			}
			else{
				return false;
			}
		}
	}
	if(v.size()){
		return false;
	}
	return true;
}

bool pali(string s){
	if(s.length()%2){
		return false;
	}
	else{
		int l=s.length();
		for(int i=0;i<l/2;i++){
			if(s[i]==s[l-1-i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S;
	cin>>S;
	if(pali(S)&&legal(S)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
