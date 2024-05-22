#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str; cin >> str;
    str = str.substr(0, 5);
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        if(str == tmp.substr(0, 5)) ans++;
    }
    cout << ans << '\n';
    return 0;
}
