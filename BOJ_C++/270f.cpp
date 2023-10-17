#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
vector<pil> g[200001];
int main() {
    fastio;
    int n, m;
    cin >> n;
    vector<ll> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    
    for(int i = 0; i < m; i++) {
        int t1, t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }


    return 0;
}