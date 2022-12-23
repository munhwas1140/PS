#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int p[51];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    p[x] = y;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m;
    int k; cin >> k;
    vector<int> know(k);
    for(int i = 0; i < k; i++) {
        cin >> know[i];
    }

    vector<vector<int>> party;
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        vector<int> tv;
        for(int j = 0; j < tmp; j++) {
            int t; cin >> t;
            tv.push_back(t);
        }
        party.push_back(tv);
    }

    for(int i = 0; i < m; i++) {
        int sz = party[i].size();
        for(int j = 1; j < sz; j++) {
            set_union(party[i][j], party[i][0]);
        }
    }



    int ans = 0;
    for(int i = 0; i < m; i++) {
        bool ok = true;
        for(int j = 0; j < party[i].size(); j++) {
            for(int l = 0; l < k; l++) {
                if(find(know[l]) == find(party[i][j])) {
                    ok = false;
                }
            }
        }
        if(ok) ans++;
    }
    cout << ans << '\n';

    return 0;
}