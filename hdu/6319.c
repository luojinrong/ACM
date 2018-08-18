#include <stdio.h>
#define maxn 10000005
typedef long long ll;
ll A, B, n, m, k, p, q, r, MOD, a[maxn], queue[maxn], q_fro, q_rear;

void pop() {
    q_fro++;
}

void re_push() {
    q_rear--;
}

void push(ll pos) {
    if (q_fro == q_rear) {
        queue[q_rear] = pos;
        q_rear++;
    }
    else {
        if (a[pos]<a[queue[q_rear - 1]]) {
            queue[q_rear++] = pos;
        }
        else {
            re_push();
            push(pos);
        }
    }
}

ll size() {
    return (q_rear - q_fro);
}

int main() {
    ll T;
    for (scanf("%lld", &T); T; T--) {
        A = B = q_fro = q_rear = 0;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &k, &p, &q, &r, &MOD);
        for (ll i = 1; i <= k; i++) {
            scanf("%lld", &a[i]);
        }
        for (ll i = k + 1; i <= n; i++) {
            a[i] = (p*a[i - 1] + q * i + r) % MOD;
        }
        for (ll i = n; i >= m; i--) {
            if (size() && queue[q_fro]>i) {
                pop();
            }
            if (i == n) {
                for (ll j = i; j >= i - m + 1; j--) {
                    push(j);
                }
            }
            else {
                push(i - m + 1);
            }
            A += a[queue[q_fro]] ^ (i - m + 1);
            B += size() ^ (i - m + 1);
        }
        printf("%lld %lld\n", A, B);
    }
}
