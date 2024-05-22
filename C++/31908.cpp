#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    map<string, vector<string>> mp;
    for(int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        if(str2 == "-") continue;
        if(!mp.count(str2)) {
            mp[str2] = vector<string>();
        }
        mp[str2].push_back(str1);
    }

    int ans = 0;
    vector<pair<string,string>> ansv;
    for(const auto& x : mp) {
        if(x.second.size() == 2) {
            ans++;
            ansv.emplace_back(x.second[0], x.second[1]);
        }
    }
    cout << ans << '\n';
    for(auto x : ansv) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
