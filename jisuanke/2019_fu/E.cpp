#include<bits/stdc++.h>
using namespace std;
const int maxn(1e6+5);
char s[maxn];
int len;
void pre(){
	int flag=0,pos,l=0,r=0;
	for(int i=len-1;i>=0;i--){
		if(flag==0&&s[i]=='('){
			flag=1;
			l++;
		}
		else if(flag==1&&s[i]=='('){
			l++;
		}
		else if(flag==1&&s[i]==')'){
			pos=i;
			r++;
			break;
		}
		else if(s[i]==')'){
			r++;
		}
	}
//	for(int i=0;i<len;i++){
//		if(i==pos2){
//			cout<<"(";
//		}
//		else if(i==pos1){
//			cout<<")";
//		}
//		else{
//			cout<<s[i];
//		}
//	}
	for(int i=0;i<pos;i++){
		cout<<s[i];
	}
	cout<<"(";
	for(int i=0;i<r-l+1;i++){
		cout<<")";
	}
	for(int i=0;i<l-1;i++){
		cout<<"()";
	}
	cout<<"\n";
}
void suf(){
	int l=0,r=0,pos;
	for(int i=len-1;i>=0;i--){
		if(s[i]=='('){
			l++;
			if(l<r){
				pos=i;
				break;
			}
		}
		else{
			r++;
		}
	}
	for(int i=0;i<pos;i++){
		cout<<s[i];
	}
	cout<<")";
	for(int i=0;i<l;i++){
		cout<<"(";
	}
	for(int i=0;i<r-1;i++){
		cout<<")";
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>s){
		len=strlen(s);
		pre();
		suf();
	}
}
