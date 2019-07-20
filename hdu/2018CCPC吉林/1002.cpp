#include<bits/stdc++.h>
using namespace std;
int T,hour;
string s1,s2,s,flag,minu;
map<string,int>m;
int main(){
	cin>>T;
	m["Beijing"]=8;
	m["Washington"]=-5;
	m["London"]=0;
	m["Moscow"]=3;
	for(int i=1;i<=T;i++){
		scanf("%d:",&hour);
		cin>>minu>>s>>s1>>s2;
		if(hour==12&&s=="AM"){
			hour=0;
		}else if(hour==12&&s=="PM"){
			s="AM";
		}else if(s=="PM"){
			hour+=12;
		}
		hour+=m[s2]-m[s1];
		flag="Today";
		if(hour>36){
			hour-=36;
			flag="Tomorrow";
			s="PM";
		}else if(hour==36){
			hour-=24;
			flag="Tomorrow";
			s="PM";
		}else if(hour>24){
			hour-=24;
			flag="Tomorrow";
			s="AM";
		}else if(hour==24){
			hour-=12;
			flag="Tomorrow";
			s="AM";
		}else if(hour>12){
			hour-=12;
			flag="Today";
			s="PM";
		}else if(hour==12){
			flag="Today";
			s="PM";
		}else if(hour>0){
			flag="Today";
			s="AM";
		}else if(hour==0){
			flag="Today";
			hour+=12;
			s="AM";
		}else if(hour>-12){
			flag="Yesterday";
			hour+=12;
			s="PM";
		}else if(hour==-12){
			flag="Yesterday";
			hour+=24;
			s="PM";
		}else{
			flag="Yesterday";
			hour+=24;
			s="AM";
		}
		cout<<"Case "<<i<<": "<<flag<<" "<<hour<<":"<<minu<<" "<<s<<endl;
	}
}
