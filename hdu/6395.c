#include <stdio.h>
#define maxn 105
#define max(a,b) {(a)>(b)?(a):(b)}
#define min(a,b) (a)>(b)?(b):(a)
typedef long long ll;
struct matrix{
	ll m[maxn][maxn];
}begin,one;
ll n,m,a,b,c,d,p,q;

void mat_times(struct matrix*a,struct matrix*b){
	struct matrix ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans.m[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans.m[i][j]+=a->m[i][k]*b->m[k][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a->m[i][j]=ans.m[i][j];
		}
	}
}

void mat_qpow(ll b){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			one.m[i][j]=i==j?1:0;
		}
	}
	while(b){
		if(b%2){
			mat_times(&one,&begin);
		}
		mat_times(&begin,&begin);
		b>>=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			begin.m[i][j]=one.m[i][j];
		}
	}
}

int main(){
	n=3;
	struct matrix zj;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			zj.m[i][j]=0;
		}
	}
	zj.m[0][0]=b;zj.m[1][0]=a;
	while(~scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&q)){
		if(q==1){
			printf("%lld\n",a);
		}
		else if(q==2){
			printf("%lld\n",b);
		}
		else{
			for(int i=3;i<=q;){
				int j=(p/i==0)?q:min(q,q/(q/i));
				zj.m[2][0]=p/i;
				begin.m[0][0]=d;begin.m[0][1]=c;begin.m[0][2]=begin.m[1][0]=begin.m[2][2]=1;begin.m[1][1]=begin.m[1][2]=begin.m[2][0]=begin.m[2][1]=0;
				mat_qpow(j-i+1);
				mat_times(&zj,&begin);
				i=j+1;
			}
			printf("%lld\n",zj.m[0][0]);
		}
	}
}
