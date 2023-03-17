#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n);
    for(string &str : a) cin >> str;

    sort(a.begin(), a.end(), [&] (const string &u, const string &v) {
        if(u.size() == v.size()) return u < v;
        return u.size() < v.size();
    });
    
    for(string str : a) cout << str << '\n';

    return 0;
}