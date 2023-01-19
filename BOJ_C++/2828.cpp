#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    int s = 1, e = m;
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        while(true) {
            if(s <= tmp && tmp <= e) break;
            else if(tmp < s) {
                s--; e--; ans++;
            } else {
                s++; e++; ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}