#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m, s, e;
int p[1000];
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
    cin >> n >> m >> s >> e;
    priority_queue<tuple<int,int,int>> pq;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        pq.push({t3, t1, t2});
    }
      
    while(!pq.empty()) {
        auto [d, a, b] = pq.top();
        pq.pop();
        set_union(a, b);
        if(find(s) == find(e)) return !(cout << d << '\n');
    }
    return 0;
}