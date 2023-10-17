#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> s;
    for(int i = 0; i < n; i++) {
        s.push_back(i);
    }

    int rounds = 0;
    vector<vector<int>> wins(n);

    while(a[s.front()] != n) {
        int x = s.front();
        s.pop_front();
        int y = s.front();
        s.pop_front();

        if(a[x] < a[y]) {
            swap(x, y);
        }
        s.push_front(x);
        wins[x].push_back(rounds++);
        s.push_back(y);
    }

    while(q--) {
        int idx, k;
        cin >> idx >> k;
        idx--;
        
        int ans = lower_bound(wins[idx].begin(), wins[idx].end(), k) - wins[idx].begin();
        
        if(a[idx] == n && k > rounds) {
            ans += k - rounds;
        }
        cout << ans << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}