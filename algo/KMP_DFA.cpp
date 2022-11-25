#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int DFA[1001][26];

void init() {
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 26; j++) {
            DFA[i][j] = 0;
        }
    }
}

void constructDFA(string &s) {
    int n = s.size();
    DFA[s[0] - 'A'][0] = 1;
    for(int x = 0, j = 1; j <= n; j++) {
        for(int c = 0; c < 26; c++) {
            DFA[c][j] = DFA[c][x];
        }

        if(j == n) break;

        DFA[s[j] - 'A'][j] = j + 1;
        x = DFA[s[j] - 'A'][x];
    }
}
void solve() {
    init();

    string s, w;
    cin >> s >> w;

    constructDFA(s);
    int cnt = 0;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j <= s.size(); j++) {
            if(DFA[i][j]) cnt++;
        }
    }
    
    int textlen = w.size();
    int patlen = s.size();
    int ans = 0;
    for(int i = 0, j = 0; i < textlen; i++) {
        j = DFA[w[i] - 'A'][j];
        if(j == patlen) {
            ans++;
        }
    }
    cout << cnt << ' ' << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}