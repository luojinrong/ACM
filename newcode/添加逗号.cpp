#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	stack<char> S;
	long long n,t=0;
	cin>>n;
	while(n){
		if(t%3==0&&t!=0){
			S.push(',');
		}
		S.push(n%10+'0');
		n/=10;
		t++;
	}
	while(!S.empty()){
		cout<<S.top();
		S.pop();
	}
	cout<<endl;
}
