#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[200001], dp[200001];
int go(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;

    if(now >= n) return 0;
    ret = 1;
    if(a[now] > 0) {
        ret += go(now + a[now] + 1);
    } else {
        ret += go(now + 1);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++) {
        cout << go(i) << ' ';
    }
    return 0;
}