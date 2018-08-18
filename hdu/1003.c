#include <stdio.h>
#define maxn 100005
int n,a[maxn],ans,sum,start,end,max,max_s,max_e;

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		start=end=max_s=max_e=1;
		ans=0;
		max=-1005;
		for(int i=1;i<=n;){
			if(ans+a[i]>max){
				ans+=a[i];
				end=i;
				if(ans>max){
					max=ans;
					max_s=start;
					max_e=end;
				}
				i++;
				if(ans<0){
					ans=0;
					start=i;
				}
				continue;
			}
			else{
				int j;
				sum=0;
				for(j=i;j<=n;j++){
					sum+=a[j];
					if(sum+ans<0){
						i++;
						ans=0;
						start=i;
						break;
					}
					if(sum>0){
						i=j+1;
						end=j;
						ans+=sum;
						if(ans>max){
							max=ans;
							max_s=start;
							max_e=end;
						}
						if(ans<0){
							ans=0;
							start=i;
						}
						break;
					}
				}
				if(j>n){
					break;
				}
			}
		}
		printf("Case %d:\n",t);
		printf("%d %d %d\n",max,max_s,max_e);
		if(t!=T){
			printf("\n");
		}
	}
}
