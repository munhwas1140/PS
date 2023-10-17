#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[52][52];
ll go(int now, int open) {
    if(now == 0) {
        if(open == 0) return 1LL;
        return 0LL;
    }

    ll &ret = dp[now][open];
    if(ret != -1) return ret;

    ret = 0;
    ret += go(now - 1, open + 1);
    if(open > 0) ret += go(now - 1, open - 1);
    return ret;
}

void trace(int now, int open, ll k) {
    if(now == 0) return ;

    if(open < 0) {
        if(k <= (1LL << (now - 1))) {
            cout << '(';
            trace(now - 1, open, k);
        } else {
            cout << ')';
            trace(now - 1, open, k - (1LL << (now - 1)));
        }
    } else {
        if(k <= (1LL << (now - 1)) - go(now - 1, open + 1)) {
            cout << '(';
            trace(now - 1, open + 1, k);
        } else {
            cout << ')';
            trace(now - 1, open - 1, k - ((1LL << (now - 1)) - go(now - 1, open + 1)));
        }
    }
}

int main() {
    fastio;
    ll n, k;
    cin >> n >> k;
    k++;
    memset(dp,-1,sizeof(dp));

    if(k > (1LL << n) - go(n, 0)) cout << -1 << '\n';
    else trace(n, 0, k);

    return 0;
}