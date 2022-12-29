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

    if(n == 1) return !(cout << (a[0] * 2) << '\n');

    sort(a.begin(), a.end());

    for(int i = 29; i >= 0; i--) {

    }

    return 0;`
}