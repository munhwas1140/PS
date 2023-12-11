#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<char> pos;
bool check[26];
int n, k;
string a, b;

ll fun() {
    ll it = 0, pre = 0, ret = 0;
    while(it < n) {
        if(a[it] != b[it] && check[a[it] - 'a'] == false) {
            ll t = it - pre;
            ret += (t * (t + 1)) / 2;
            pre = it + 1;
        }
        it++;
    }

    ll t = it - pre;
    ret += (t * (t + 1)) / 2;
    return ret;
}
ll go(int idx, int num) {
    if(num == k) {
        return fun();
    }
    ll ret = -1;
    for(int i = idx; i < pos.size(); i++) {
        check[pos[i] - 'a'] = true;
        ret = max(ret, go(i + 1, num + 1));
        check[pos[i] - 'a'] = false;
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    cin >> a >> b;

    pos.clear();
    memset(check, false, sizeof(check));
    for(auto &c : a) {
        pos.push_back(c);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    if(k >= pos.size()) {
        cout << (ll(n) * ll(n + 1)) / 2 << '\n';
    } else {
        cout << go(0, 0) << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}