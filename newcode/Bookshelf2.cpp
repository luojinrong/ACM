#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn(25);
ll n,h[maxn],b,ans;
void dfs(ll p,ll sum){
    sum+=h[p];
    if(sum>=0&&sum<ans){
        ans=sum;
    }
    if(p==n){
        return;
    }
    dfs(p+1,sum);
    dfs(p+1,sum-h[p]);
}
int main(){
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        ans+=h[i];
    }
    ans-=b;
    dfs(1,-1*b);
    cout<<ans<<endl;
}
