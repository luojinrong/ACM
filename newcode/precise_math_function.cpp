#include<stdio.h>
#include<math.h>
const double pi=3.1415926535;//不够精确
int main(){
    int t;
    scanf("%d",&t);
    for(;t;t--){
        double n,x,v;
		scanf("%lf%lf",&n,&x); 
		v=pow(n,pi);
		if(x==1){
			printf("%.1lf",v);
		}		
		else if(x==2){
			printf("%.2lf",v);
		}
		else if(x==3){
			printf("%.3lf",v);
		}
		else if(x==4){
			printf("%.4lf",v);
		}
		else if(x==5){
			printf("%.5lf",v);
		}
		else{
			printf("%.6lf",v);
		}
		printf("\n");
    }
}
