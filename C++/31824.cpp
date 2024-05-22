#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    for(int i = 0; i < m; i++) {
        string str; cin >> str;
        int sz = str.size();
        bool f = false;
        for(int j = 0; j < sz; j++) {
            for(int k = 1; k <= sz - j; k++) {
                string substr = str.substr(j, k);
                if(mp.count(substr)) {
                    f = true;
                    cout << mp[substr];
                }
            }
        }
        if(!f) cout << -1;
        cout << '\n';
    }
    return 0;
}
