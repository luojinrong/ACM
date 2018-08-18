#include <math.h>
#include <stdio.h>
#define maxn 100005
typedef long long LL;
const LL mod=1e9+7;
int a,b;
LL ways,Jc[maxn];

void calJc()    //求maxn以内的数的阶乘
{
    Jc[0] = Jc[1] = 1;
    for(LL i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}
/*
//拓展欧几里得算法求逆元
void exgcd(LL a, LL b, LL &x, LL &y)    //拓展欧几里得算法
{
    if(!b) x = 1, y = 0;
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

LL niYuan(LL a, LL b)   //求a对b取模的逆元
{
    LL x, y;
    exgcd(a, b, x, y);
    return (x + b) % b;
}
*/

//费马小定理求逆元
LL pow_LL(LL a, LL n, LL p)    //快速幂 a^n % p
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

LL niYuan(LL a, LL b)   //费马小定理求逆元
{
    return pow_LL(a, b - 2, b);
}

LL C(LL a, LL b)    //计算C(a, b)
{
    return Jc[a] * niYuan(Jc[b], mod) % mod
        * niYuan(Jc[a - b], mod) % mod;
}
//double Inchoose(int n,int m){
//	if(m>n){
//		return 0;
//	}
//	if(m<n/2.0){
//		m=n-m;
//	}
//	double s1=0;
//	for(int i=m+1;i<=n;i++){
//		s1+=log((double)i);
//	}
//	double s2=0;
//	int ub=n-m;
//	for(int i=2;i<=ub;i++){
//		s2+=log((double)i);
//	}
//	return s1-s2;
//}
//
//double choose(int n,int m){
//	if(m>n){
//		return 0;
//	}
//	return exp(Inchoose(n,m));
//}

int main(){
	int T;
	calJc();
	for(scanf("%d",&T);T;T--){
		ways=1;
		scanf("%d%d",&a,&b);
		if(b>0){
			ways+=a;
		}
		if(b>=a-1){
			ways+=a;
		}
		if(b>=a){
			ways+=1;
		}
		if(b<=a/2){
			for(int i=2;i<=b;i++){
				ways=(ways+C(a,i))%mod;
			}
		}
		else{
			for(int i=2;i<=a/2;i++){
				if((a%2==1&&a-i<=b)||(a%2==0&&(a-i)!=(a/2)&&a-i<=b)){
					ways=(ways+2*C(a,i))%mod;
				}
				else{
					ways=(ways+C(a,i))%mod;
				}
			}
		}
		printf("%lld\n",ways);
	}
}
