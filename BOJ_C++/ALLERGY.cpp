#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int best;
map<string, int> name;
vector<int> eaters[50], canEat[50];
void init() {
    name.clear();
    for(int i = 0; i < 50; i++) {
        eaters[i].clear();
        canEat[i].clear();
    }
}
void go(vector<int> &edible, int chosen) {
    if(chosen >= best) return ;
    
    int it = 0;
    while(it < n && edible[it] > 0) it++;
    
    if(it == n) {
        best = chosen;
        return ;
    }
    
    for(int i = 0; i < canEat[it].size(); i++) {
        int food = canEat[it][i];
        for(int j = 0; j < eaters[food].size(); j++) {
            edible[eaters[food][j]]++;
        }
        go(edible, chosen + 1);
        for(int j = 0; j < eaters[food].size(); j++) {
            edible[eaters[food][j]]--;
        }
    }
    return ;
}
void solve() {
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        name[str] = i;
    }

    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            string str; cin >> str;
            eaters[i].push_back(name[str]);
            canEat[name[str]].push_back(i);
        }
    }
    
    best = 1e9;
    vector<int> edible(n);
    go(edible, 0);
    cout << best << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}