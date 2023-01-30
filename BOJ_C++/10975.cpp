#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    int ans = 0;
    vector<bool> check(n);
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        bool ok = false;
        if(idx > 0 && check[idx - 1]) ok = true;
        if(idx < n - 1 && check[idx + 1]) ok = true;
        if(!ok) ans++;
        check[idx] = true;
    }
    cout << ans << '\n';
    return 0;
}