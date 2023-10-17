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
    if(k > n - 1) cout << "Impossible" << '\n';
    else {
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        k = n - k;
        rotate(a.begin(), a.begin() + k - 1, a.begin() + k);
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}