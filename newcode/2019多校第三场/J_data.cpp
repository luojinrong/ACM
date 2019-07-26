//数据
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("./J.in","w",stdout);
	srand(time(NULL));
	ll T=rand()%100;
	cout<<T<<endl;
	while(T--){
		ll Q=rand()%100,M=rand()%Q;
		cout<<Q<<" "<<M<<endl;
		for(int j=0;j<Q;j++){
			cout<<rand()%2<<" ";
			for(int i=0;i<3;i++){
				cout<<rand()%10;
			}
			cout<<" "<<rand()%100<<endl;
		}
	}
}
