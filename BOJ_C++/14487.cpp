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
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << accumulate(a.begin(), a.end(), 0) - *max_element(a.begin(), a.end()) << '\n';

    return 0;
}