#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    string str;
    cin >> n >> str;

    int it = 0;
    while(it < n && str[it] == '0') it++;
    if(it == n) {
        return !(cout << "0" << '\n');
    }

    int it2 = it;
    while(it2 < n && str[it2] == '1') it2++;
    if(it2 == n) {
        return !(cout << "0" << '\n');
    }
    string s = str.substr(it);
    string ans = s;
    for(int i = 1; i <= it2 - it; i++) {
        string cand = s;
        for(int j = 0; i + j < n; j++) {
            if(s[j] == '1') {
                cand[i + j] = '1';
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << '\n';

    return 0;
}