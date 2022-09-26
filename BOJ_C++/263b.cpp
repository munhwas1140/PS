#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
vector<int> g[51];
int go(int now, int dep) {
    if(now == n) return dep;
    int ret = -1;
    for(int &next : g[now]) {
        ret = go(next, dep + 1);
        if(ret != -1) return ret;
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int tmp; cin >> tmp;
        g[tmp].push_back(i);
    }
    cout << go(1,0) << '\n';
    return 0;
}