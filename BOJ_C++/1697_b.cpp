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
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<ll> psum(n + 1);
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }

    while(m--) {
        int x, y;
        cin >> x >> y;
        cout << psum[n - x + y] - psum[n - x] << '\n';
    }

    return 0;
}