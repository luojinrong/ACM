#include <stdio.h>
#define maxn 100005
int n,w[maxn],bit,num,x,u,v;

int h_b(int w){
	if(w>>1){
		return 1+h_b(w>>1);
	}
	return 0;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		x=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&w[i]);
			x^=w[i];
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
		}
		if(!x){
			printf("D\n");
		}
		else{
			printf("Q\n");
//			bit=h_b(x);
//			for(int i=0;i<n;i++){
//				if((w[i]>>bit)%2){
//					num++;
//				}
//			}
//			if(num%2){
//				printf("Q\n");
//			}
//			else{
//				printf("T\n");
//			}
		}
	}
}
