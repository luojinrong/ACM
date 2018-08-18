#include <stdio.h>
#include <math.h>

const double PI=3.1415926535897932384626433;
double a,b,ans;

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%lf%lf",&a,&b);
		ans=2*b+a*PI-0.0000005;
		printf("%.6lf\n",ans);
	}
}
