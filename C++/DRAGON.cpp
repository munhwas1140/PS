#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k, l;
const int MAX = 1e9 + 1;
int len[51];
void precalc() {
    len[0] = 1;
    for(int i = 1; i <= 50; i++) {
        len[i] = min(MAX ,len[i-1] * 2 + 2);
    }
}
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
char expand(const string& dragonCurve, int generations, int k) {
    if(generations == 0) {
        return dragonCurve[k];
    }

    for(int i = 0; i < dragonCurve.size(); i++) {
        if(dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if(k >= len[generations]) {
                k -= len[generations];
            } else if(dragonCurve[i] == 'X') {
                return expand(EXPAND_X, generations - 1, k);
            } else {
                return expand(EXPAND_Y, generations - 1, k);
            }
        } else if(k > 0) {
            --k;
        } else {
            return dragonCurve[i];
        }
    }
    return '#';
}
void solve() {
    cin >> n >> k >> l;
    k -= 1;
    for(int i = 0; i < l; i++) {
        cout << expand("FX",n,k + i);
    }
    cout << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    precalc();
    while(tc--) {
        solve();
    }
    return 0;
}