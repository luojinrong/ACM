#include<iostream>

using namespace std;

typedef long long ll;

ll N,a,b;
const ll maxn=100005;

struct treenode{
	ll addmark,time;
}node[maxn*4];

void pushUp(ll root){

}

void build(ll root,ll nstart,ll nend){
	node[root].addmark=0;
	if(nstart==nend){
		node[root].time=0;
		return;
	}
	ll mid=(nstart+nend)>>1;
	build(root*2+1,nstart,mid);
	build(root*2+2,mid+1,nend);
	pushUp(root);
}

void pushDown(ll root){
	if(node[root].addmark){
		node[root*2+1].addmark+=node[root].addmark;
		node[root*2+2].addmark+=node[root].addmark;
		node[root*2+1].time+=node[root].addmark;
		node[root*2+2].time+=node[root].addmark;
		node[root].addmark=0;
	}
}

void add(ll root,ll nstart,ll nend,ll astart,ll aend){
	if(nstart>aend||nend<astart){
		return;
	}
	else if(astart<=nstart&&aend>=nend){
		node[root].time+=1;
		node[root].addmark+=1;
		return;
	}
	pushDown(root);
	ll mid=(nstart+nend)>>1;
	add(root*2+1,nstart,mid,astart,aend);
	add(root*2+2,mid+1,nend,astart,aend);
	pushUp(root);
}

void query(ll root,ll nstart,ll nend,ll n){
	if(nstart>n||nend<n){
		return;
	}
	else{
		if(nstart==nend){
			printf("%lld%c",node[root].time," \n"[nstart==N-1]);
			return;
		}
		pushDown(root);
		ll mid=(nstart+nend)>>1;
		query(root*2+1,nstart,mid,n);
		query(root*2+2,mid+1,nend,n);
	}
}

int main(){
	while(scanf("%lld",&N),N){
		build(0,0,N-1);
		ll a,b;
		for(ll i=0;i<N;i++){
			scanf("%lld%lld",&a,&b);
			add(0,0,N-1,a-1,b-1);
		}
		for(ll i=0;i<N;i++){
			query(0,0,N-1,i);
		}
	}
}
