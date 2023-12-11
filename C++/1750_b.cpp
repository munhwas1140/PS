#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string str;
    cin >> str;

    ll z, o, mlen, tmp;
    z = o = 0;
    mlen = tmp = 1;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') z++;
        else o++;

        if(i < n) {
            if(str[i] == str[i + 1]) {
                tmp++;
            } else {
                mlen = max(mlen, tmp);
                tmp = 1;
            }
        }
    }
    cout << max(z * o, mlen * mlen) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}