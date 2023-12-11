#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        int sz = str.size();
        vector<bool> check(26);
        bool ok = true;
        for(int j = 0; j < sz; j++) {
            if(!check[str[j] - 'a']) {
                check[str[j] - 'a'] = true;
                while(j < sz - 1 && str[j] == str[j + 1]) j++;
            } else ok = false;
        }
        ans += ok;
    }
    cout << ans << '\n';

    return 0;
}