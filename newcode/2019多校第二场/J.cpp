#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define per(i,a,n) for (int i=a;i<n;i++)
#define rep(i,a,n) for (int i=n-1;i>=a;i--)
const ll mod(998244353);
const ll INF(0x3f3f3f3f3f3f3f3f);
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
const int MAXN(5e5+7);
 
int T;
int Q, M;
int hdp, memt, cnt;
int cache[MAXN], pre[MAXN], nxt[MAXN];
 
struct trie{
    struct nd{
        int pos;
        nd* nxt[10];
        nd(): pos(0) {
            per(i, 0, 10) {
                nxt[i]= nullptr;
            }
        }
    };
    nd *rt;
    trie() {
        rt = new nd();
    }
    void insert(const string& str, const int& len, int dex, const int& pos, nd* rtt) {
        if(dex==len) {
            rtt->pos = pos;
            return;
        }
        if(rtt->nxt[str[dex]-'0'] == nullptr) {
            rtt->nxt[str[dex]-'0'] = new nd;
        }
        insert(str, len, dex+1, pos, rtt->nxt[str[dex]-'0']);
    }
    int sou(const string& str, const int& len, int dex, nd* rtt) {
        if(dex==len) {
            return rtt->pos;
        }
        if(rtt->nxt[str[dex]-'0'] == nullptr) {
            return 0;
        }
        return sou(str, len, dex+1, rtt->nxt[str[dex]-'0']);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE	
	freopen("./J.in","r",stdin);
	freopen("./J1.out","w",stdout);
#endif
    cin >> T;
    while(T--) {
        trie whrim;
        memt = 0;
        hdp = cnt = 1;
        int opt, vv, dex;
        string str;
        cin >> Q >> M;
        per(i, 1, Q+1) {
            cin >> opt >> str >> vv;
            if(!opt) {
                cache[cnt] = vv;
                pre[cnt] = cnt-1;
                nxt[cnt] = cnt+1;
                dex = whrim.sou(str, str.length(), 0, whrim.rt);
                whrim.insert(str, str.length(), 0, cnt, whrim.rt);
                cnt++;
                if(dex<hdp) {
                    cout << vv << '\n';
                    if(memt>=M) {
                        hdp = nxt[hdp];
                    } else {
                        memt++;
                    }
                } else {
                    cout << cache[dex] << '\n';
                    pre[nxt[dex]] = pre[dex];
                    nxt[pre[dex]] = nxt[dex];
                    if(hdp==dex) hdp=nxt[hdp];
                }
            } else {
                dex = whrim.sou(str, str.length(), 0, whrim.rt);
                if(dex>=hdp) {
                    if (vv == 1) {
                        dex = nxt[dex];
                    } else if (vv == -1) {
                        dex = pre[dex];
                    }
                }
                if(dex>=hdp && dex<cnt) {
                    cout << cache[dex] << '\n';
                } else {
                    cout << "Invalid" << '\n';
                }
            }
        }
    }
 
    return 0;
}
