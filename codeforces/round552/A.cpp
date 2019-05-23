#include<bits/stdc++.h>
using namespace std;
int a,b,c,a_b,a_c,b_c,a_b_c,maxx,id;

void swap(int *x,int *y){
	*x^=*y;
	*y^=*x;
	*x^=*y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a_b>>a_c>>b_c>>a_b_c;
	if(a_b>maxx){
		id=1;
		maxx=a_b;
	}
	if(a_c>maxx){
		id=2;
		maxx=a_c;
	}
	if(b_c>maxx){
		id=3;
		maxx=b_c;
	}
	if(a_b_c>maxx){
		id=4;
		maxx=a_b_c;
	}
	//cout<<maxx<<endl;
	//cout<<a_b<<" "<<a_c<<" "<<b_c<<" "<<a_b_c<<endl;
	if(maxx>a_b_c){
		if(id==1){
			swap(&a_b_c,&a_b);
		}
		if(id==2){
			swap(&a_b_c,&a_c);
		}
		if(id==3){
			swap(&a_b_c,&b_c);
		}
	}
	//cout<<a_b<<" "<<a_c<<" "<<b_c<<" "<<a_b_c<<endl;
	a=a_b_c-b_c;
	b=a_b_c-a_c;
	c=a_b_c-a_b;
	cout<<a<<" "<<b<<" "<<c<<"\n";
}
