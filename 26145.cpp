#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int main() {
    fastio;
    cin >> n >> m;
    vector<int> a(n + m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + m; j++) {
            int tmp; cin >> tmp;
            a[j] += tmp;
            a[i] -= tmp;
        }
    }

    for(int i = 0; i < n + m; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}