#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int p[200001];
int Find(int x) {
    if(p[x] < 0) return x;
    return p[x] = Find(p[x]);
}
int set_union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(p[x] < p[y]) {
        p[y] = x;
        return -p[x];
    } else {
        p[x] = y;
        return -p[y];
    }
}
int main() {
    fastio;
    cin >> n >> m;
    vector<tuple<int,int,int>> e;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        e.push_back({t3, t2, t1});
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum += p[i];
        p[i] *= -1;
    }

    int ans = sum;
    sort(e.begin(), e.end());
    for(auto [c, x, y] : e) {
        x = Find(x);
        y = Find(y);
        if(x != y) {
            sum -= set_union(x, y);
            sum += c;
            ans = min(ans, sum);
        }
    }
    cout << ans << '\n';
    return 0;
}