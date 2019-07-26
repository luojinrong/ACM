#include<bits/stdc++.h>
#define FIN freopen("./D.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const int maxn(1e2+5);
const double pi=acos(-1);
ll n,k,w[maxn];
string e[maxn];
struct clique{//存储一个团
    ll w;//当前团的权值
    int num;//当前团内点数
    vector<int> p;//当前团内各点
    bool operator < (const clique &c) const {
        return w>c.w;
    }
}cli[maxn],qt;
priority_queue<clique> q;
int main(){
#ifndef ONLINE_JUDGE
    FIN;
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        cli[i].w=w[i];
        cli[i].num=0;
        cli[i].p.push_back(i);
        q.push(cli[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>e[i];
    }
    k--;
    if(k==0){
        cout<<0<<endl;
        return 0;
    }
    while(!q.empty()){
        qt=q.top();
        q.pop();
        k--;
        if(k==0){
            cout<<qt.w<<endl;
            return 0;
        }
        int now=qt.p[qt.num];
        bool flag;
        for(int i=now+1;i<=n;i++){
            flag=1;
            for(int j=0;j<=qt.num;j++){
                if(e[qt.p[j]][i-1]=='0'){
                    flag=0;
                    break;
                }
            }
            if(flag){
                qt.num++;
                qt.p.push_back(i);
                qt.w+=w[i];
                q.push(qt);
                qt.num--;
				qt.p.pop_back();
                qt.w-=w[i];
            }
        }
    }
    cout<<-1<<endl;
}
