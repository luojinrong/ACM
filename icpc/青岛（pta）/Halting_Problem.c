#include<stdio.h>
#include<string.h>
#define maxn 10005
typedef long long ll;
struct OP{
	char s[5];
	ll xb;
	ll v;
	ll k;
}ops[maxn];
ll r,n;

ll add(struct OP *op){
	r=(r+op->v)%256;
	return (op->xb+1);
}

ll beq(struct OP *op){
	if(r==op->v){
		return op->k;
	}
	else{
		return (op->xb+1);
	}
}

ll bne(struct OP *op){
	if(r==op->v){
		return (op->xb+1);
	}
	else{
		return op->k;
	}
}

ll blt(struct OP *op){
	if(r<op->v){
		return (op->k);
	}
	else{
		return (op->xb+1);
	}
}

ll bgt(struct OP*op){
	if(r>op->v){
		return (op->k);
	}
	else{
		return (op->xb+1);
	}
}



int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",ops[i].s);
			if(!strcmp(ops[i].s,"add")){
				scanf("%lld",&ops[i].v);
			}
			else{
				scanf("%lld%lld",&ops[i].v,&ops[i].k);
			}
		}
	}
}
