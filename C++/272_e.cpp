#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &v : a) cin >> v;
    vector<vector<int>> vals(m + 1);    
    for(int i = 0; i < n; i++) {
        if(a[i] >= n) continue;
        int l = (a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1));
        int r = min(m + 1, (n - a[i] + i) / (i + 1));
        for(int j = l; j < r; j++) {
            vals[j].push_back(a[i] + (i + 1) * j);
        }
    }

    for(int i = 1; i <= m; i++) {
        int sz = vals[i].size();
        vector<bool> exi(sz + 1);
        for(int v : vals[i]) {
            if(v <= sz) exi[v] = true;
        }
        int res = 0;
        while(exi[res]) res++;
        cout << res << '\n';
    }
    return 0;
}