#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    map<char, pii> mp;
    string k[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    set<char> l;
    for(char c : "qwertasdfgzxcv") l.insert(c);

    for(int i = 0; i < 3; i++) {
        int sz = k[i].size();
        for(int j = 0; j < sz; j++) {
            mp[k[i][j]] =  make_pair(i, j);
        }
    }

    char x, y;
    string str;
    cin >> x >> y >> str;
    pii nl = mp[x], nr = mp[y];
    
    int ans = 0;
    for(char &c : str) {
        pii tmp = mp[c];
        if(l.count(c)) {
            ans += abs(nl.first - tmp.first) + abs(nl.second - tmp.second);
            nl = tmp;
        } else {
            ans += abs(nr.first - tmp.first) + abs(nr.second - tmp.second);
            nr = tmp;
        }
    }
    cout << ans + (int)str.size() << '\n';

    return 0;
}