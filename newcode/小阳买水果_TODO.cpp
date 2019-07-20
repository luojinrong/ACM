#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(2e6+5);
ll n,a[maxn],sum[maxn],ans,l,r,i;
int main(){
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        //printf("%lld ",sum[i]);
    }
    l=1,r=n;
    while(l<r){
        i=(l+r)>>1;
        for(int j=1;j+i-1<=n;j++){
            if(sum[j+i-1]>sum[j-1]){
                ans=i;
                //cout<<i<<" "<<j<<endl;
                break;
            }
        }
        if(ans==i){
            l=i+1;
        }else{
            r=i-1;
        }
        //cout<<l<<" "<<r<<endl;
    }
    /*for(int i=n;i>0;i--){
        for(int j=1;j+i-1<=n;j++){
            if(sum[j+i-1]>sum[j-1]){
                ans=i;
                //cout<<i<<" "<<j<<endl;
                break;
            }
        }
        if(ans){
            break;
        }
    }*/
    printf("%lld\n",ans);
}
