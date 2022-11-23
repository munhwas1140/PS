#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> makefail(string &w) {
    int m = w.size();
    vector<int> fail(m);
    for(int i = 1, j = 0; i < m; i++) {
        while(j > 0 && w[i] != w[j]) j = fail[j - 1];
        if(w[i] == w[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> kmp(string &s, string &w) {
    vector<int> ret;
    vector<int> fail = makefail(w);
    
    int n = s.size();
    int m = w.size();
    for(int i = 0, j = 0; i < n; i++) {
        while(j > 0 && s[i] != w[j]) {
            j = fail[j - 1];
        }
        if(s[i] == w[j]) {
            if(j == m - 1) {
                ret.push_back(i - m + 2);
                j = fail[j];
            } else {
                j++;
            }
        }
    }
    return ret;
}
int main() {
    fastio;
    string s, w;
    getline(cin, s);
    getline(cin, w);

    vector<int> ans = kmp(s, w);
    cout << ans.size() << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }
    return 0;
}