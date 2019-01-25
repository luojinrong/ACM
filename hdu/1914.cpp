//带优先级的二分匹配
#include<iostream>
#include<vector>
#include<string>
#define INF 0x3fffffff
using namespace std;

const int N=100;//最大节点对数，根据题目修改
int n,wCount;//n表示匹配对数，wCount表示当前已创建女方个数（创建男方时使用）
struct PARTNER{
	string name;//姓名
	int next;//单身时下一个匹配目标，这是在perfect中的下标
	int current;//当前匹配目标的下标，这是在W[]或M[]中的下标，若单身则为-1
	int pCount;//被喜欢的目标个数
	int perfect[N];//喜欢程度顺序表，越喜欢排在越前面
}M[N],W[N];

int GetFreeMan(){//获取一个单身男性下标，若不存在单身男性则返回-1
	for(int i=0;i<n;i++){
		if(M[i].current==-1){
			return i;
		}
	}
	return -1;
}

int GetManPos(int wid,int mid){//获取男方mid在女方wid喜欢程度顺序表的位置，若不存在则返回INF（即超级不喜欢）
	for(int i=0;i<W[wid].pCount;i++){
		if(W[wid].perfect[i]==mid){
			return i;
		}
	}
	return INF;
}

void gale_shapley(){//算法部分
	int mid=GetFreeMan();//获取单身男性
	while(mid>=0){//若还存在单身男性
		int wid=M[mid].perfect[M[mid].next];//获取该单身男性下一个追求目标
		if(W[wid].current==-1){//下一个追求目标单身，直接在一起
			W[wid].current=mid;
			M[mid].current=wid;
		}
		else{//名花有主
			int tmid=W[wid].current;//获取女方的当前CP在M[]中的下标
			if(GetManPos(wid,mid)<GetManPos(wid,tmid)){//若女方更喜欢追求者，则与原CP分手
				M[tmid].current=-1;
				M[mid].current=wid;
				W[wid].current=mid;
			}
			++M[mid].next;//不论成功与否，不再考虑当前追求的女方，更改下一个目标
		}
		mid=GetFreeMan();//继续获取单身男性
	}
}

int GetWoman(string name){//获取名为name的女性在W[]中的下标，不存在返回-1
	for(int i=0;i<n;i++){
		if(name==W[i].name){
			return i;
		}
	}
	return -1;
}

int GetMan(string name){//获取名为name的男性在M[]中的下标，不存在返回-1（由于先创建了男性，一般不会不存在）
	for(int i=0;i<n;i++){
		if(name==M[i].name){
			return i;
		}
	}
	return -1;
}

void AddMan(int p){//创建一个男性
	cin>>M[p].name;//输入姓名
	M[p].current=-1;//令单身
	M[p].next=0;//追求目标从最喜欢的开始
	M[p].pCount=n;//根据题目修改，一般都等于n
}

void AddWoman(int p){//创建一个女性
	cin>>W[p].name;
	W[p].current=-1;
	W[p].next=0;
	W[p].pCount=n;
}

void print(){//打印稳定匹配方案，根据题目要求格式修改
	for(int i=0;i<n;i++){
		cout<<M[i].name<<" "<<W[M[i].current].name<<endl;
	}
}

void createlist(){//创建喜欢程度顺序表
	for(int i=0;i<n;i++){
		string tmp,tmp_name;
		cin>>tmp;
		tmp_name=tmp[0];
		int mp=GetMan(tmp_name),pos=0;
		for(int j=2;j<2+n;j++){
			tmp_name=tmp[j];
			int wp=GetWoman(tmp_name);
			M[mp].perfect[pos++]=wp;
		}
	}
	for(int i=0;i<n;i++){
		string tmp,tmp_name;
		cin>>tmp;
		tmp_name=tmp[0];
		int wp=GetWoman(tmp_name),pos=0;
		for(int j=2;j<2+n;j++){
			tmp_name=tmp[j];
			int mp=GetMan(tmp_name);
			W[wp].perfect[pos++]=mp;
		}
	}
}

int main(){
	int T;
	for(cin>>T;T;T--){
		cin>>n;
		wCount=0;
		for(int i=0;i<n;i++){
			AddMan(i);
		}
		for(int i=0;i<n;i++){
			AddWoman(i);
		}
		createlist();
		gale_shapley();
		print();
		if(T!=1){
			cout<<endl;
		}
	}
}
