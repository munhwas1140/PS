#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[26];
int n, m;
string s1, s2;
int main() {
    fastio;
    cin >> n >> s1;
    for(int i = 0; i < n; i++) {
        check[s1[i] - 'a'] = true;
    }

    cin >> m >> s2;
    for(int i = 0; i < m; i++) {
        if(!check[s2[i] - 'a']) return !(cout << -1 << '\n');
    }
    
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt++;
        while(s1[(cnt + n - 1) % n] != s2[i]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}