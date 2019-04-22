//带优先级的二分匹配
#include<iostream>
#include<vector>
#include<string>
#define INF 0x3fffffff
using namespace std;

const int N=505;
int match_M[N],match_W[N],n,wCount;
struct PARTNER{
	string name;
	int next;
	int current;
	int pCount;
	int perfect[N];
}M[N],W[N];

int GetFreeMan(){
	for(int i=0;i<n;i++){
		if(M[i].current==-1){
			return i;
		}
	}
	return -1;
}

int GetManPos(int wid,int mid){
	for(int i=0;i<W[wid].pCount;i++){
		if(W[wid].perfect[i]==mid){
			return i;
		}
	}
	return INF;
}

void gale_shapley(){
	int mid=GetFreeMan();
	while(mid>=0){
		int wid=M[mid].perfect[M[mid].next];
		if(W[wid].current==-1){
			W[wid].current=mid;
			M[mid].current=wid;
		}
		else{
			int tmid=W[wid].current;
			if(GetManPos(wid,mid)<GetManPos(wid,tmid)){
				M[tmid].current=-1;
				M[mid].current=wid;
				W[wid].current=mid;
			}
			++M[mid].next;
		}
		mid=GetFreeMan();
	}
}

int GetWoman(string name){
	for(int i=0;i<wCount;i++){
		if(name==W[i].name){
			return i;
		}
	}
	return -1;
}

int GetMan(string name){
	for(int i=0;i<n;i++){
		if(name==M[i].name){
			return i;
		}
	}
	return -1;
}

void AddMan(int p){
	cin>>M[p].name;
	M[p].current=-1;
	M[p].next=0;
	M[p].pCount=n;
	int pos=0;
	string tmp_name;
	for(int i=0;i<M[p].pCount;i++){
		cin>>tmp_name;
		int wp=GetWoman(tmp_name);
		if(wp!=-1){
			M[p].perfect[pos++]=wp;
		}
		else{
			W[wCount].name=tmp_name;
			M[p].perfect[pos++]=wCount++;
		}
	}
}

void AddWoman(){
	string tmp_name;
	cin>>tmp_name;
	int wp=GetWoman(tmp_name);
	if(wp==-1){
		W[wCount].name=tmp_name;
		wp=wCount++;
	}
	W[wp].current=-1;
	W[wp].next=0;
	W[wp].pCount=n;
	int pos=0;
	for(int i=0;i<W[wp].pCount;i++){
		cin>>tmp_name;
		int mp=GetMan(tmp_name);
		if(mp!=-1){
			W[wp].perfect[pos++]=mp;
		}
	}
}

void print(){
	for(int i=0;i<n;i++){
		cout<<M[i].name<<" "<<W[M[i].current].name<<endl;
	}
}

int main(){
	while(cin>>n){
		wCount=0;
		for(int i=0;i<n;i++){
			AddMan(i);
		}
		for(int i=0;i<n;i++){
			AddWoman();
		}
		gale_shapley();
		print();
	}
}
