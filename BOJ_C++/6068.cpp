#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<pii> a(n);
    for(auto &[x, y] : a) {
        cin >> y >> x;
    }
    sort(a.rbegin(), a.rend());

    int now = a[0].first;
    for(auto [x, y] : a) {
        if(now > x) {
            now = x;
        }
        now -= y;
    }
    cout << (now < 0 ? -1 : now) << '\n';
    return 0;
}