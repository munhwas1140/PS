#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, k;
    cin >> n >> k;
    list<int> a;
    for(int i = 1; i <= n; i++) {
        a.push_back(i);
    }

    list<int>::iterator kill = a.begin();
    while(n > 2) {
        kill = a.erase(kill);
        if(kill == a.end()) kill = a.begin();
        --n;
        for(int i = 0; i < k - 1; i++) {
            ++kill;
            if(kill == a.end()) kill = a.begin();
        }
    }
    cout << a.front() << ' ' << a.back() << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}