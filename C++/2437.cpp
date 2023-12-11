#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > sum + 1) {
            return !(cout << sum + 1 << '\n');
        }
        sum += a[i];
    }
    cout << sum + 1 << '\n';
    return 0;
}