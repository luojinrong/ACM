#include<iostream>
#include<cstring>
#define maxn 10005
using namespace std;
char s[maxn];
const char str[]="abcdefghijklmnopqrstuvwxyz";

void pre(){
	int pos=0;
	for(int i=1;pos<maxn;i++){
		for(int j=0;j<i;j++){
			s[pos++]=str[j%26];
		}
	}
}

int main(){
	int K;
	pre();
//	for(int i=0;i<100;i++){
//		cout<<s[i];
//	}
	cin>>K;
	while(K--){
		int N;
		cin>>N;
		cout<<s[N-1]<<endl;
	}
}
