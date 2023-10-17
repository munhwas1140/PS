#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p1[1001], p2[1001];
set<int> row[1001], col[1001];
map<int, int> mp[1001];
set<pii> rows;
int Find(int *par, int x) {
    if(par[x] < 0) return x;
    return par[x] = Find(par,par[x]);
}
void set_union(int *par, int x, int y) {
    x = Find(par, x);
    y = Find(par, y);
    par[x] = y;
}
void Merge_row(int x, int y) {
    for(auto tmp : row[y]) {
        mp[x][tmp] = mp[y][tmp];                                       
        row[x].insert(tmp);
        col[tmp].erase(y);
        col[tmp].insert(x);
    }
}
void Merge_col(int x, int y) {
    for(auto tmp : col[y]) {
        mp[tmp][x] = mp[tmp][y];
        col[x].insert(tmp);
        row[tmp].erase(y);
        row[tmp].insert(x);
    }
}
int main() {
    fastio;
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    memset(p1,-1,sizeof(p1));
    memset(p2,-1,sizeof(p2));
    
    for(int i = 0; i < m1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union(p1, t1, t2);
    }

    for(int i = 0; i < m2; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union(p2, t1, t2);
    }

    if(m1 < m2) swap(p1, p2);

    for(int i = 1; i <= n; i++) {
        int t1 = Find(p1, i);
        int t2 = Find(p2, i);
        mp[t1][t2] = i;
        row[t1].insert(t2);
        col[t2].insert(t1);
    }
    for(int i = 1; i <= n; i++) {
        if(Find(p1, i) == i) {
            rows.insert(make_pair(-row[i].size(), i));
        }
    }
    set<int>::iterator it;
    vector<pii> ans;
    while(rows.size() > 1) {
        int x = rows.begin()->second;
        rows.erase(rows.begin());
        int y = rows.begin()->second;
        rows.erase(rows.begin());
        if(row[x].size() < row[y].size()) {
            swap(x, y);
        }
        it = row[x].begin();
        int a = *it;
        int b = *row[y].begin();
        if(a == b) {
            a = *(++it);
        }
        ans.push_back({mp[x][a], mp[y][b]});
        if(col[a].size() < col[b].size()) swap(a, b);
        Merge_row(x, y);
        Merge_col(a, b);
        rows.insert({-row[x].size(), x});
    }
    cout << ans.size() << '\n';
    for(auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}