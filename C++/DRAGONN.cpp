#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, p, l;
const int MOD = 1e9 + 1;
int gene[51];
char go(const string &now, int g, int k) {
    if(g == 0) {
        return now[k];
    }

    for(int i = 0; i < now.size(); i++) {
        if(now[i] == 'X' || now[i] == 'Y') {
            if(k >= gene[g]) {
                k -= gene[g];
            } else if(now[i] == 'X') {
                return go("X+YF", g - 1, k);
            } else {
                return go("FX-Y", g - 1, k);
            }
        } else if(k == 0) {
            return now[i];
        } else {
            k--;
        }
    }
    return '#';
}
void solve() {
    cin >> n >> p >> l;
    
    for(int i = 0; i < l; i++) {
        cout << go("FX", n, p + i - 1);
    }
    cout << '\n';
}
int main() {
    fastio;
    gene[0] = 1;
    for(int i = 1; i <= 50; i++) {
        gene[i] = min(MOD, gene[i - 1] * 2 + 2);
    }
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}