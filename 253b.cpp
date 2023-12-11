#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m;
int main() {
    fastio;
    cin >> n >> m;
    vector<pii> pos;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == 'o') pos.push_back({i, j});
        }
    }
    cout << abs(pos[0].first - pos[1].first) + abs(pos[0].second - pos[1].second) << '\n';
    return 0;
}