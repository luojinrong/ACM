#include <stdio.h>
#include <string.h>
typedef long long ll;
const int maxn=2e7+5;
ll ans[maxn],n,an;

bool check[2*maxn];
int phi[2*maxn];
int prime[2*maxn];
int tot;    //  素数个数

void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return ;
}

ll gcd(ll a,ll b){
	return a%b?gcd(b,a%b):b;
}

int main(){
	int T;
	phi_and_prime_table(2*maxn);
	ans[1]=(ll)(phi[2]/2.0+0.5);
	for(int i=2;i<maxn;i++){
		ans[i]=ans[i-1]+(ll)(phi[2*i]/2.0+0.5);
	}
	for(scanf("%d",&T);T;T--){
		scanf("%lld",&n);
		printf("%lld\n",ans[n]-1);
	}
}
