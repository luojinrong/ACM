#include <stdio.h>
#include <string.h>
typedef long long ll;
ll A[10],L,Q;
ll M[21][21],sum_raw[21],sum_col[21],sum_M;
ll sum;
void draw_M(){
	ll cursor=0;
	memset(sum_raw,0,sizeof(int));
	memset(sum_col,0,sizeof(int));
	sum_M=0;
	for(ll i=0;i<=4*L;i++){
		for(ll j=0;j<=i;j++){
			if(j<2*L&&(i-j)<2*L){
				M[j][i-j]=A[cursor];
			}
			cursor=(cursor+1)%L;
		}
	}
	for(ll i=0;i<2*L;i++){
		for(ll j=0;j<2*L;j++){
			sum_raw[i]+=M[j][i];
			sum_col[i]+=M[i][j];
		}
		sum_M+=sum_raw[i];
	}
}
ll get_num(ll x,ll y){
	ll pos;
	if((x+y)%2==1){
		pos=(((x+y+1)/2)%L)*((x+y)%L)+x;
	}
	else{
		pos=((x+y+1)%L)*(((x+y)/2)%L)+x;
	}
	return A[pos%L];
}

int main(){
	ll T;
	for(scanf("%lld",&T);T;T--){
		scanf("%lld",&L);
		for(ll i=0;i<L;i++){
			scanf("%lld",&A[i]);
		}
		scanf("%lld",&Q);
		draw_M();
		for(ll i=0;i<Q;i++){
			sum=0;
			ll x0,x1,y0,y1;
			scanf("%lld%lld%lld%lld",&x0,&y0,&x1,&y1);
			sum+=((x1-x0)/(2*L))*((y1-y0)/(2*L))*sum_M;
			ll l_left=y0+(y1-y0)%(2*L),h_left=x0+(x1-x0)%(2*L);
			for(ll j=y0;j<=l_left;j++){
				sum+=((x1-x0)/(2*L))*sum_raw[j%(2*L)];
			}
			for(ll j=x0;j<=h_left;j++){
				sum+=((y1-y0)/(2*L))*sum_col[j%(2*L)];
			}
			for(ll j=x0;j<=h_left;j++){
				for(ll k=y0;k<=l_left;k++){
					sum+=get_num(j,k);
				}
			}
			printf("%lld\n",sum);
		}
//		for(int i=0;i<2*L;i++){
//			for(int j=0;j<2*L;j++){
//				printf("%d ",M[i][j]);
//			}
//			printf("\n");
//		}
	}
}
