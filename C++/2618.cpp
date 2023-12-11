#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, w;
vector<pii> a;
int getDist(int x, int y) {
    return abs(a[x].first - a[y].first) + abs(a[x].second - a[y].second);
}
int dp[1002][1002];
int go(int x, int y) {
    if(x == w + 1 || y == w + 1) return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    
    int next = max(x, y) + 1;
    ret = min(go(next, y) + getDist(x, next), go(x, next) + getDist(y, next));
    return ret;
}
void trace(int x, int y) {
    if(x == w + 1 || y == w + 1) return ;
    int next = max(x, y) + 1;
    int t1 = go(next, y) + getDist(x, next);
    int t2 = go(x, next) + getDist(y, next);
    if(t1 < t2) {
        cout << 1 << '\n';
        trace(next, y);
    } else {
        cout << 2 << '\n';
        trace(x, next);
    }
}
int main() {
    fastio;
    cin >> n >> w;
    a.resize(w + 2);
    a[0] = {1, 1};
    a[1] = {n, n};
    for(int i = 2; i <= w + 1; i++) {
        cin >> a[i].first >> a[i].second;
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << '\n';
    trace(0, 1);

    return 0;
}