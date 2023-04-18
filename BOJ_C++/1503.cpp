#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<bool> check(1001);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        check[tmp] = true;
    }
    
    int ans = 1e9;
    for(int i = 1; i <= 250; i++) {
        if(check[i]) continue;
        for(int j = 1; j <= 250; j++) {
            if(check[j]) continue;
            for(int k = 1; k <= 250; k++) {
                if(check[k]) continue;
                ans = min(ans, abs(n - i * j * k));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}