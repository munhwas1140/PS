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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int it = i;
        while(it + 1 < n && a[i] > a[it + 1]) it++;
        ans = max(ans, it - i);
        i = it;
    }
    cout << ans << '\n';

    return 0;
}