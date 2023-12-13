#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[x, y] : a) {
        cin >> y >> x;
    }
    sort(a.begin(), a.end());
    cout << a[0].second << ' ' << a[0].first << '\n';


    return 0;
}