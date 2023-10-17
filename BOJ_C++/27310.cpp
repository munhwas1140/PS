#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    cin >> str;
    int ans = str.size() + 2;
    for(char &c : str) {
        if(c == '_') ans += 5;
    }
    cout << ans << '\n';
    return 0;
}