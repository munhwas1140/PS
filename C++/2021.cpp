#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, l;
    cin >> n >> l;
    vector<vector<int>> line(l, vector<int>());
    vector<vector<int>> plat(n + 1,vector<int>());
    vector<vector<pii>> g(n + 1,vector<pii>());
    vector<int> dist(l, -1);
    for(int i = 0; i < l; i++) {
        while(1) {
            int tmp; cin >> tmp;
            if(tmp == -1) break;
            plat[tmp].push_back(i);
            line[i].push_back(tmp);
        }
    }

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < line[i].size() - 1; j++) {
            int now = line[i][j];
            int next = line[i][j + 1];
            g[now].push_back({next, i});
            g[next].push_back({now, i});

        }
    }

    

    return 0;
}