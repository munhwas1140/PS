#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m, k;
int a[10001];
int p[10001];
int cost[10001];
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
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cost[i] = 1e9;
    }

    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union(t1, t2);
    }
    
    for(int i = 1; i <= n; i++) {
        int x = find(i);
        cost[x] = min(cost[x], a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cost[i] == 1e9) continue;
        ans += cost[i];
    }
    if(ans > k) cout << "Oh no" << '\n';
    else cout << ans << '\n';
    return 0;
}