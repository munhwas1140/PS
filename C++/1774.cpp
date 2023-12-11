#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int p[1000];
int n, m;
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[x] = y;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m;
    vector<pair<ll, ll>> pos(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(find(t1) == find(t2)) continue;
        merge(t1, t2);
        cnt++;
    }
    
    priority_queue<tuple<ll,int,int>> pq;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(find(i) != find(j)) {
                ll tmp = (pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + 
                        (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second);
                pq.push({-tmp, i, j}); 
            }
        }
    }
    
    double ans = 0;
    for(; cnt < n - 1;) {
        auto [x, a, b] = pq.top();
        pq.pop();   
        if(find(a) != find(b)) {
            ans += sqrt(-x);
            merge(a,b);
            cnt++;
        }
    }
      
    cout << fixed << setprecision(2);
    cout << ans << '\n';
    return 0;
}