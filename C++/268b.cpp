#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    string s, t;
    cin >> s >> t;
    if(s.size() > t.size()) {
        cout << "No" << '\n';
    } else {
        bool ok = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) {
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}