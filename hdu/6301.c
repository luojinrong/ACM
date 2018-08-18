#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fact{
	int l;
	int r;
}facts[100005];
int n,m,array[100005],now;
int comp(const void*a,const void*b){
	return (((struct fact*)a)->l-((struct fact*)b)->l);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		now=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&facts[i].l,&facts[i].r);
		}
		qsort(facts,m,(sizeof(struct fact)),comp);
		for(int i=0;i<m;i++){
			if(now<facts[i].l){
				for(int j=now+1;j<facts[i].l;j++){
					array[j]=1;
				}
				for(int j=facts[i].l;j<=facts[i].r;j++){
					array[j]=j-facts[i].l+1;
				}
				now=facts[i].r;
			}
			else if(now>=facts[i].r){
				continue;
			}
			else{
				int j,len=facts[i].r-facts[i].l+2,d=1;
				int *flag=(int*)malloc(sizeof(int)*len);
				memset(flag,0,(sizeof(int)*len));
				for(j=facts[i].l;j<=now;j++){
					if(array[j]<len){
						flag[array[j]]=1;
					}
				}
				for(j=now+1;j<=facts[i].r;j++){
					for(;d<len;d++){
						if(!flag[d]){
							array[j]=d;
							flag[d]=1;
							break;
						}
					}
				}
				now=facts[i].r;
				free(flag);
			}
		}
		if(now<n){
			for(int i=now+1;i<=n;i++){
				array[i]=1;
			}
			now=n;
		}
		printf("%d",array[1]);
		for(int i=2;i<=n;i++){
			printf(" %d",array[i]);
		}
		printf("\n");
	}	
}

//1
//10 4
//1 3
//5 9
//2 7
//6 8
