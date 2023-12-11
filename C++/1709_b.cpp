#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 2);
    vector<ll> diffl(n + 1), diffr(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i > 1) {
            if(a[i] > a[i - 1]) continue;
            diffl[i] = a[i - 1] - a[i];
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] > a[i + 1]) continue;
        diffr[i] = a[i + 1] - a[i];
    }

    vector<ll> pl(n + 1), pr(n + 1);
    for(int i = 1; i <= n; i++) {
        pl[i] = pl[i - 1] + diffl[i];
    }

    for(int i = n; i >= 1; i--) {
        pr[i] = pr[i + 1] + diffr[i];
    }

    while(m--) {
        int s, e;
        cin >> s >> e;
        if(s < e) {
            cout << pl[e] - pl[s] << '\n';
        } else {
            cout << pr[e] - pr[s] << '\n';
        }
    }
}
int main() {
    fastio;
    solve();
    return 0;
}