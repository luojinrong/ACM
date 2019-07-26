#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int maxn(30);
const int esp=-100000;
#define MAXN maxn
#define upf(a,b,c) for(int a=b;a<=c;++a)
#define drf(a,b,c) for(int a=b;a>=c;--a)
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll dp[3005],n;
ll p[3005];
ll inv[3005];
void getn(ll m){
    p[0]=1;
    p[1]=m;
    upf(i,2,m){
        p[i]=(p[i-1]*(m-i+1))%mod*inv[i];
        p[i]%=mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    upf(i,1,3000){
        inv[i]=powmod(i,mod-2);
    }
    dp[0]=0;
    dp[1]=0;
    upf(i,2,3000){
        getn(i);
        ll tmp=powmod(2,i);
        dp[i]=((tmp*i*(i-1))%mod*powmod(((tmp-1)*4)%mod,mod-2))%mod;
        ll ttp=powmod((tmp-1)%mod,mod-2);
        upf(j,2,i-1){
            dp[i]+=((p[j]*dp[j])%mod)*ttp;
            dp[i]%=mod;
        }
    }
    upf(i,1,3000){
        dp[i]+=dp[i-1];
        dp[i]%=mod;
    }
    upf(i,1,3000){
        dp[i]*=inv[i];
        dp[i]%=mod;
    }
    while(cin>>n){
        cout<<dp[n]<<endl;
    }

}
