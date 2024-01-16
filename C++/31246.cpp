#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[i] = t2 - t1;
    }
    sort(a.begin(), a.end());
    cout << max(a[k - 1], 0) << '\n';
    return 0;
}