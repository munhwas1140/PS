#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> p(n);
    vector<int> xp, yp;
    for(auto &[x, y] : p) {
        cin >> x >> ' ' >> y;
        xp.push_back(x);
        yp.push_back(y);
    }
    sort(xp.begin(), xp.end());
    xp.erase(unique(xp.begin(), xp.end()), xp.end());
    sort(yp.begin(), yp.end());
    yp.erase(unique(yp.begin(), yp.end()), yp.end());

    


    return 0;
}