//Neko Finds Grapes
#include<iostream>
#define maxn 100005
using namespace std;
int n,m,a[2],b[2],tmp;

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a[tmp%2]++;
	}
	for(int i=0;i<m;i++){
		cin>>tmp;
		b[tmp%2]++;
	}
	cout<<(a[0]>b[1]?b[1]:a[0])+(a[1]>b[0]?b[0]:a[1])<<endl;
}
