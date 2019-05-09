#include<iostream>
#include<cstring>
using namespace std;
#define maxn 5005
char a[maxn],b[maxn];
int maxx,tmp;

int main(){
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len-1;i++){
		if(a[i]==((a[i+1]>='a'&&a[i+1]<='z')?(a[i+1]-'a'+'A'):(a[i+1]-'A'+'a'))){
			tmp=2;
			int l=i-1,r=i+2;
			while(l>=0&&r<len){
				if(a[l]==((a[r]>='a'&&a[r]<='z')?(a[r]-'a'+'A'):(a[r]-'A'+'a'))){
					tmp+=2;
					l--;r++;
				}
				else{
					break;
				}
			}
			if(tmp>maxx){
				maxx=tmp;
			}
		}
	}
	cout<<maxx<<"\n";
}
