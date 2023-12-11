#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<bool> check(1001, false);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        check[tmp] = true;
    }
    
    vector<int> cand;
    for(int i = 1; i <= 51; i++) cand.push_back(i);
    for(int i = n - 51; i <= n + 51; i++) {
        if(i >= 1) cand.push_back(i);
    }

    int ans = 1e9;
    for(auto x : cand) {
        if(check[x]) continue;
        for(auto y : cand) {
            if(check[y]) continue;
            for(auto z : cand) {
                if(check[z]) continue;
                ans = min(ans, abs(n - x * y * z));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}