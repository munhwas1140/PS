#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int par[1001];
int find(int x) {
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

void set_union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x != y) {
        par[x] = y;
    }
}

int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    memset(par,-1,sizeof(par));
    vector<int> b(k);
    priority_queue<tuple<int,int,int>> q;
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }

    for(int i = 1; i < k; i++) {
        set_union(b[0], b[i]);
    }
    
    for(int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        q.push({-v, s, e});
    }

    int cnt = k;
    
    int ans = 0;
    while(cnt < n) {
        auto [v, s, e] = q.top();
        q.pop();
        v = -v;
    
        s = find(s);
        e = find(e);
        if(s != e) {
            cnt++;
            set_union(s, e);
            ans += v;
        }
    }

    cout << ans << '\n';

    return 0;
}