#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int n; cin >> n;
    vector<string> s(n), t(n);
    map<string, int> ID;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        if(!ID.count(s[i])) ID[s[i]] = 1;
        else ID[s[i]]++;
        if(s[i] == t[i]) continue;
        if(!ID.count(t[i])) ID[t[i]] = 1;
        else ID[t[i]]++;
    }
    
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(ID[s[i]] > 1 && ID[t[i]] > 1) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}