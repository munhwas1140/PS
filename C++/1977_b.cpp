#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    int mx = 0;
    vector<int> a;
    for(int i = 0; i < 30; i++) {
        if(n & (1 << i)) {
            mx = max(mx, i);
        }
    }

    for(int i = 0; i <= mx; i++) {
        if(n & 1 << i) a.push_back(1);
        else a.push_back(0);
    }

    for(int i = 1; i < a.size(); i++) {
        if(a[i] == 2) {
            a[i] = 0;
            if(i + 1 == a.size()) a.push_back(1);
            else a[i + 1] += 1;
        }
        if(a[i] == 1 && a[i - 1] == 1) {
            a[i - 1] = -1;
            a[i] = 0;
            if(i + 1 == a.size()) a.push_back(1);
            else a[i + 1] += 1;
        }
    }

    cout << a.size() << '\n';
    for(const int &x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}