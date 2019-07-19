/*
a3=a1+a2
a4=a3+a2=a1+2a2
a5=a4+a3=2a1+3a2
a6=a5+a4=3a1+5a2

f[1]=1,f[2]=1;f[n]=f[n-1]+f[n-2]
1 1 2 3 5 8 13

ak=f[k-2]a1+f[k-1]a2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fib;
ll i,l,r,k,p,m,ans;
int main(){
    ll T;
    cin>>T;
    fib.push_back((ll)1);
    fib.push_back((ll)1);
    while(T--){
        cin>>i>>l>>r>>k>>p>>m;
        if(k>(ll)fib.size()){
            for(ll j=fib.size();j<k;j++){
                fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
            }
        }
        ans=0;
        for(ll j=l;j<=r;j++){
            if((fib[k-3]*i+fib[k-2]*j)%p==m){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

