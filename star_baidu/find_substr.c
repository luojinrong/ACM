#include <stdio.h>
#include <string.h>
#define maxn 100005

int ans_num,n,q,li,ri;
char ans_c;
char str[maxn];
struct tree{
	int nstart,nend,min_num;
	char min_c;
}node[maxn*4];

void build(int root,int l,int r){
	if(l==r){
		node[root].min_c=str[l];
		node[root].min_num=1;
		return;
	}
	int mid=(l+r)>>1;
	build(root*2+1,l,mid);
	build(root*2+2,mid+1,r);
	if(node[root*2+1].min_c==node[root*2+2].min_c){
		node[root].min_c=node[root*2+1].min_c;
		node[root].min_num=node[root*2+1].min_num+node[root*2+2].min_num;
	}
	else{
		if(node[root*2+1].min_c>node[root*2+2].min_c){
			node[root].min_c=node[root*2+2].min_c;
			node[root].min_num=node[root*2+2].min_num;
		}
		else{
			node[root].min_c=node[root*2+1].min_c;
			node[root].min_num=node[root*2+1].min_num;
		}
	}
}

void query(int root,int nstart,int nend,int qstart,int qend){
	if(qstart>nend||qend<nstart){
		return;
	}
	else if(qstart<=nstart&&qend>=nend){
		if(ans_c==0){
			ans_c=node[root].min_c;
			ans_num=node[root].min_num;
		}
		else if(node[root].min_c==ans_c){
			ans_num+=node[root].min_num;
		}
		else if(node[root].min_c<ans_c){
			ans_c=node[root].min_c;
			ans_num=node[root].min_num;
		}
		return;
	}
	else{
		int mid=(nstart+nend)>>1;
		query(root*2+1,nstart,mid,qstart,qend);
		query(root*2+2,mid+1,nend,qstart,qend);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d%s",&n,&q,str);
		build(0,0,n-1);
		printf("Case #%d:\n",t);
		for(int Q=0;Q<q;Q++){
			scanf("%d%d",&li,&ri);
			ans_c=ans_num=0;
			query(0,0,n-1,li-1,ri-1);
			printf("%d\n",ans_num);
		}
	}
}
