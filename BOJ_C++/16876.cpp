#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
map<string, int> mp[101];
int n;
string st;
// koo = 1(str > st),  cube = 0;
int go(string str, int t) {
    if(t == n) {
        // cout << str << ' ' << st << '\n';
        // cout << (str > st) << '\n';
        return (str > st ? 1 : 0);
    }

    if(mp[t].count(str)) return mp[t][str];
    int &ret = mp[t][str];
    if(t % 2 == 0) ret = 0;
    else ret = 1;

    for(int i = 0; i < 4; i++) {
        char tmp = str[i];
        if(str[i] == '9') str[i] = '0';
        else str[i]++;
        
        if(t % 2 == 0) {
            ret = max(ret, go(str, t + 1));
        } else {
            ret = min(ret, go(str, t + 1));
        }
        str[i] = tmp;
    }
    
    return ret;
}
int main() {
    fastio;
    string str; cin >> str;
    cin >> n;
    st = str;

    if(go(str, 0)) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}