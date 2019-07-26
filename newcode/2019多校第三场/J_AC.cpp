#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
struct Node
{
    string s, v;
    Node() {}
    Node(string s, string v) : s(s), v(v) {}
};
int q, m;
list<Node> lt;
unordered_map<string, list<Node>::iterator> mp;
int main()
{
	freopen("./J.in","r",stdin);
	freopen("./J2.out","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &q, &m);
        lt.clear();
        mp.clear();
        while (q--)
        {
            int op;
            char s[20];
            scanf("%d%s", &op, s);
            if (op == 0)
            {
                char v[20];
                scanf("%s", v);
                if (mp.find(s) != mp.end())
                {
                    auto it = mp[s];
                    strcpy(v, it->v.data());
                    lt.erase(it);
                }
                lt.emplace_back(s, v);
                mp[s] = prev(lt.end());
                printf("%s\n", v);
                if ((int)lt.size() > m)
                {
                    mp.erase(lt.begin()->s);
                    lt.pop_front();
                }
            }
            else
            {
                int v;
                scanf("%d", &v);
                if (mp.find(s) == mp.end())
                {
                    printf("Invalid\n");
                    continue;
                }
                auto pos = mp[s];
                if ((pos == lt.begin() && v == -1) ||
                    (next(pos) == lt.end() && v == 1))
                {
                    printf("Invalid\n");
                    continue;
                }
                if (v == 1) pos = next(pos);
                else if (v == -1) pos = prev(pos);
                printf("%s\n", pos->v.data());
            }
        }
    }
    return 0;
}
