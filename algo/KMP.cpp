#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> makeFail(string &s) {
    int n = s.size();
    vector<int> ret(n);
    for(int i = 1, j = 0; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = ret[j - 1];
        if(s[i] == s[j]) ret[i] = ++j;
    }
    return ret;
}
int KMP(string &s, string &w) {
    vector<int> fail = makeFail(s);
    int ans = 0;
    int n = w.size();
    int m = s.size();

    for(int i = 0; i < m; i++) {
        cout << fail[i] << ' ';
    }
    cout << '\n';

    for(int i = 0, j = 0; i < n; i++) {
        while(j > 0 && s[j] != w[i]) j = fail[j - 1];
        if(w[i] == s[j]) {
            if(j == m - 1) {
                ans++;
                j = fail[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}
void solve() {
    string s, w;
    cin >> s >> w;
    cout << KMP(s, w) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}