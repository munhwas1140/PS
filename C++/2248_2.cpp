#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int N, L;
ll I;
int dp[32][32];
int go(int idx, int rem) {
    if(idx == 0 || rem == 0) return 1;
    int &ret = dp[idx][rem];
    if(ret != -1) return ret;
    ret = go(idx - 1, rem) + go(idx - 1, rem - 1);
    return ret;
}
void print(int idx, int rem, ll k) {
    if(idx == 0) return ;
    int tmp = go(idx - 1, rem);
    if(k <= tmp) {
        cout << 0;
        print(idx - 1, rem, k);
    } else {
        cout << 1;
        print(idx - 1, rem - 1, k - go(idx - 1, rem));
    }
}
int main() {
    fastio;
    cin >> N >> L >> I;
    memset(dp,-1,sizeof(dp));
    go(N, L);
    print(N, L, I);
    return 0;
}