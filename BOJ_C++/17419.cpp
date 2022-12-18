#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += str[i] - '0';
    }
    cout << ans << '\n';
    return 0;
}