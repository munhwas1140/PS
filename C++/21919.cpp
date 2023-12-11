#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool p[1000001];
int main() {
    fastio;
    for(int i = 2; i <= 1000000; i++) {
        if(!p[i]) {
            for(int j = i * 2; j <= 1000000; j += i) {
                p[j] = true;
            }
        }
    }

    int n; cin >> n;
    
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        if(!p[tmp]) {
            ans = lcm(ans, tmp);
        }
    }

    cout << (ans == 1 ? -1 : ans) << '\n';

    return 0;
}