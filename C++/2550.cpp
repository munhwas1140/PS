#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        cout << a[i].first << ' ' << a[i].second << '\n';
    }

    return 0;
}