#include<iostream>
#include<list>
#include<queue>
using namespace std;
typedef long long ll;

ll m,n;

class Graph{
	ll V;
	list<ll> *adj;
	queue<ll> q;
	ll *indegree;
	ll *sorted;
public:
	Graph(ll V);
	~Graph();
	void addedge(ll a,ll b);
	bool top_sort();
	ll getSort(ll v);
};

Graph::Graph(ll V){
	this->V=V;
	adj=new list<ll>[V];
	sorted=new ll[V];
	indegree=new ll[V];
	for(ll i=0;i<V;i++){
		indegree[i]=0;
	}
}

Graph::~Graph(){
	delete[] adj;
	delete[] sorted;
	delete[] indegree;
}

void Graph::addedge(ll a,ll b){
	adj[a].push_back(b);
	++indegree[b];
}

bool Graph::top_sort(){
	for(ll i=0;i<V;i++){
		if(!indegree[i]){
			q.push(i);
		}
	}
	ll count = 0;
	while(!q.empty()){
		ll v=q.front();
		q.pop();
		sorted[count++]=v;
		list<ll>::iterator beg=adj[v].begin();
		for(;beg!=adj[v].end();beg++){
			if(!(--indegree[*beg])){
				q.push(*beg);
			}
		}
	}
	if(count < V){
		return false;
	}
	else{
		return true;
	}
}

ll Graph::getSort(ll v){
	return sorted[v];
}

int main(){
	ll T;
	for(scanf("%lld",&T);T;T--){
		scanf("%lld%lld",&n,&m);
		Graph G(n);
		ll a,b;
		while(m--){
			scanf("%lld%lld",&a,&b);
			G.addedge(a-1,b-1);
		}
		G.top_sort();
		for(ll i=0;i<n;i++){
			printf("%lld%c",G.getSort(i)+1," \n"[i==n-1]);
		}
	}
}
