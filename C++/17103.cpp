#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> p;
bool check[1000001];
void solve() {
    int n; cin >> n;

    int it = 0, sz = p.size();
    int ans = 0;
    while(it < sz && p[it] <= n / 2) {
        if(!check[n - p[it]]) ans++;
        it++;
    }
    cout << ans << '\n';
}
void init() {
    check[0] = check[1] = true;
    for(int i = 2; i <= 1000000; i++) {
        if(!check[i]) {
            p.push_back(i);
            for(int j = i + i; j <= 1000000; j += i) {
                check[j] = true;
            }
        }
    }
}
int main() {
    fastio;
    init();
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}