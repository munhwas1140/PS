#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        for(int j = 0; j < n; j++) {
            cin >> a >> b;
        }
        cout << "Material Management " << i << '\n';
        cout << "Classification ---- End!" << '\n';
    }

    return 0;
}