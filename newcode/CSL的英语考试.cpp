#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1005;
int list[26],len1,len2,minlen;
char s1[maxn],s2[maxn];

int com_char(int index){
	return list[s1[index-1]-'a']-list[s2[index-1]-'a'];
}

int compare(int index){
	if(index==minlen){
		return com_char(index);
	}
	else{
		int v=com_char(index);
		if(v==0){
			return compare(index+1);
		}
		else{
			return v;
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<26;i++){
			char t;
			cin>>t;
			list[t-'a']=i;
		}
		for(int i=0;i<n;i++){
			cin>>s1>>s2;
			len1=strlen(s1);
			len2=strlen(s2);
			minlen=len1>len2?len2:len1;
			int v=compare(1);
			if(v==0){
				if(len1==len2){
					cout<<"="<<endl;
				}
				else if(len1>len2){
					cout<<">"<<endl;
				}
				else{
					cout<<"<"<<endl;
				}
			}
			else if(v>0){
				cout<<">"<<endl;
			}
			else{
				cout<<"<"<<endl;
			}
		}
	}
}
