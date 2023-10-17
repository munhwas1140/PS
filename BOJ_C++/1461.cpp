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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int it = 0;
    int ans = 0;
    while(it < n && a[it] < 0) {
        ans += -a[it] * 2;
        it += m;
    }
    it = n - 1;
    while(it >= 0 && a[it] > 0) {
        ans += a[it] * 2;
        it -= m;
    }
    cout << ans - max(abs(a[0]), abs(a[n - 1])) << '\n';

    return 0;
}