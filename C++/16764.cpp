#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[50505];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[y] += p[x];
        p[x] = y;
    }
}

map<int,vector<int>> mp;
bool check[50505];
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(5));

    vector<int> pos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a[i][j];
            mp[a[i][j]].push_back(i);
            pos.push_back(a[i][j]);
        }
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    int ans = (n * (n - 1)) / 2;

    for(int x : pos) {
        memset(check,false,sizeof(check));
        int sz = mp[x].size();
        int tmp = (sz * (sz - 1)) / 2;
        for(int num : mp[x]) {
            cout << num << ' ';
            int tt = find(num);
            if(p[tt] != -1 && check[tt] == false) {
                check[tt] = true;
                int t = -p[tt];
                tmp -= (t * (t - 1)) / 2;
            }
        }
        ans -= tmp;

        for(int i = 0; i < sz - 1; i++) {
            set_union(mp[x][i], mp[x][i + 1]);
        }
        
    }

    cout << ans << '\n';
    return 0;
}