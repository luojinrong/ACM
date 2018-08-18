#include <stdio.h>

int A,B,n,m,k,p,q,r,MOD,a[10000005],max[10000005],count[10000005];

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		A=B=max[0]=count[0]=0;
		scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&MOD);
		for(int i=1;i<=k;i++){
			scanf("%d",&a[i]);
			if(a[i]>max[i-1]){
				max[i]=a[i];
				count[i]=count[i-1]+1;
			}	
			else{
				max[i]=max[i-1];
				count[i]=count[i-1];
			}
		}
		for(int i=k+1;i<=n;i++){
			a[i]=(p*a[i-1]+q*i+r)%MOD;
			if(a[i]>max[i-1]){
				max[i]=a[i];
				count[i]=count[i-1]+1;
			}	
		}
		for(int i=1;i<=n-m+1;i++){
			A+=max[i]^i;
			B+=count[i]^i;
			printf("------------\n%d %d\n",A,B);
		}
		printf("%d %d\n",A,B);
	}
}
