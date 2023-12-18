#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    int n;
    cin >> str >> n;
    int sz = str.size() - 1;
    int ans = 0, now = 1;
    for(int i = sz; i >= 0; i--) {
        char c = str[i];
        if('0' <= c && c <= '9') {
            ans += (c - '0') * now;
        } else {
            ans += ((c - 'A') + 10) * now;
        }
        now *= n;
    }
    cout << ans << '\n';
    return 0;
}