#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n, m;
int p[1001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return ;
    p[x] = y;
}
int main() {
    memset(p,-1,sizeof(p));
    fastio;
    cin >> n >> m;
    
    priority_queue<tuple<int, int, int>> pq;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t1 == t2) continue;
        pq.push({-t3, t1, t2});
    }

    int cnt = 0;
    int ans = 0;
    while(cnt < n - 1) {
        auto [d, x, y] = pq.top();
        pq.pop();
        d = -d;
        x = find(x);
        y = find(y);
        if(x != y) {
            set_union(x, y);
            ans += d;
            cnt++;
        }
    }
    cout << ans << '\n';
    return 0;
}