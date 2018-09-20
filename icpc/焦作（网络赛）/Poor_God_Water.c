//#include <stdio.h>
//#define maxn 100
//typedef long long ll;
//ll mm[maxn],mf[maxn],ff[maxn],fm[maxn],cc[maxn],cm[maxn],cf[maxn],fc[maxn],mc[maxn],all[maxn];
//int main(){
//	mm[3]=2,mf[3]=3,ff[3]=2,fm[3]=3,cc[3]=2,cm[3]=2,cf[3]=2,fc[3]=2,mc[3]=2,all[3]=20;
//	for(int i=4;i<maxn;i++){
//		mm[i]=fm[i-1]+cm[i-1];
//		mf[i]=fm[i-1]+mm[i-1]+cm[i-1];
//		ff[i]=mf[i-1]+cf[i-1];
//		fm[i]=mf[i-1]+ff[i-1]+cf[i-1];
//		cc[i]=fc[i-1]+mc[i-1];
//		cm[i]=cc[i-1]+fc[i-1];
//		cf[i]=cc[i-1]+mc[i-1];
//		fc[i]=mf[i-1]+ff[i-1];
//		mc[i]=mm[i-1]+fm[i-1];
//		all[i]=mm[i]+mf[i]+ff[i]+fm[i]+cc[i]+cm[i]+cf[i]+fc[i]+mc[i];
//		printf("all[%d] = %lld\n",i,all[i]);
//	}
//}
