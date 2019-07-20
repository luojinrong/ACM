#include<bits/stdc++.h>
using namespace std;
int m[20],s[20],p[20],z[20],ans_m[20],ans_s[20],ans_p[20],ans_z[20];
int have_m[20],have_s[20],have_p[20],have_z[20];
char tmp[5];
bool judge(){
	int flag=0;
	for(int i=1;i<10;i++){
		if(m[i]==2){
			flag++;
		}
		if(p[i]==2){
			flag++;
		}
		if(s[i]==2){
			flag++;
		}
		if(z[i]==2){
			flag++;
		}
	}
	if(flag>1){
		return true;
	}
	return false;
}
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	while(cin>>tmp){
		memset(m,0,sizeof(m));
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		memset(z,0,sizeof(z));
		memset(ans_m,0,sizeof(ans_m));
		memset(ans_s,0,sizeof(ans_s));
		memset(ans_p,0,sizeof(ans_p));
		memset(ans_z,0,sizeof(ans_z));
		memset(have_m,0,sizeof(have_m));
		memset(have_s,0,sizeof(have_s));
		memset(have_p,0,sizeof(have_p));
		memset(have_z,0,sizeof(have_z));
		if(tmp[1]=='m'){
			m[tmp[0]-'0']++;
		}
		else if(tmp[1]=='s'){
			s[tmp[0]-'0']++;
		}
		else if(tmp[1]=='p'){
			p[tmp[0]-'0']++;
		}
		else if(tmp[1]=='z'){
			z[tmp[0]-'0']++;
		}
		for(int i=0;i<12;i++){
			cin>>tmp;
			if(tmp[1]=='m'){
				m[tmp[0]-'0']++;
				if(m[tmp[0]-'0']==4){
					have_m[tmp[0]-'0']=-1;
				}
			}
			else if(tmp[1]=='s'){
				s[tmp[0]-'0']++;
				if(s[tmp[0]-'0']==4){
					have_s[tmp[0]-'0']=-1;
				}
			}
			else if(tmp[1]=='p'){
				p[tmp[0]-'0']++;
				if(p[tmp[0]-'0']==4){
					have_p[tmp[0]-'0']=-1;
				}
			}
			else if(tmp[1]=='z'){
				z[tmp[0]-'0']++;
				if(z[tmp[0]-'0']==4){
					have_z[tmp[0]-'0']=-1;
				}
			}
		}
		for(int i=1;i<10;i++){
			while(m[i]>=1&&m[i+1]>=1&&m[i+2]>=1){//0110->1110 0111
				m[i]--;
				m[i+1]--;
				m[i+2]--;
			}
		}
		for(int i=1;i<10;i++){
			while(s[i]>=1&&s[i+1]>=1&&s[i+2]>=1){//0110->1110 0111
				s[i]--;
				s[i+1]--;
				s[i+2]--;
			}
		}
		for(int i=1;i<10;i++){
			while(p[i]>=1&&p[i+1]>=1&&p[i+2]>=1){//0110->1110 0111
				p[i]--;
				p[i+1]--;
				p[i+2]--;
			}
		}
		if(judge()){
			for(int i=0;i<10;i++){
				if(m[i]==2){
					ans_m[i]++;
				}
				if(s[i]==2){
					ans_s[i]++;
				}
				if(p[i]==2){
					ans_p[i]++;
				}
				if(z[i]==2){
					ans_z[i]++;
				}
			}
		}
		else{
			for(int i=0;i<10;i++){
				if(m[i]==0&&m[i+1]==1&&m[i+2]==1){
					ans_m[i]++;
					ans_m[i+3]++;
				}
				else if(m[i]==0&&m[i+1]==1&&m[i+2]==0){
					ans_m[i+1]++;
				}
			}
			for(int i=0;i<10;i++){
				if(s[i]==0&&s[i+1]==1&&s[i+2]==1){
					ans_s[i]++;
					ans_s[i+3]++;
				}
				else if(s[i]==0&&s[i+1]==1&&s[i+2]==0){
					ans_s[i+1]++;
				}
			}
			for(int i=0;i<10;i++){
				if(p[i]==0&&p[i+1]==1&&p[i+2]==1){
					ans_p[i]++;
					ans_p[i+3]++;
				}
				else if(p[i]==0&&p[i+1]==1&&p[i+2]==0){
					ans_p[i+1]++;
				}
			}
			for(int i=1;i<8;i++){
				if(z[i]==1){
					ans_z[i]++;
				}
			}
		}
		for(int i=1;i<10;i++){
			if(ans_m[i]&&have_m[i]!=-1){
				cout<<i<<"m\n";
			}
		}
		for(int i=1;i<10;i++){
			if(ans_s[i]&&have_s[i]!=-1){
				cout<<i<<"s\n";
			}
		}
		for(int i=1;i<10;i++){
			if(ans_p[i]&&have_p[i]!=-1){
				cout<<i<<"p\n";
			}
		}
		for(int i=1;i<8;i++){
			if(ans_z[i]&&have_z[i]!=-1){
				cout<<i<<"z\n";
			}
		}
	}
}
