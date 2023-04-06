#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {-1,-1,-1,0,1,1,1,0,-1};
int dy[] = {-1,0,-1,-1,-1,0,1,1,1};

void change(vector<vector<int>> mp, vector<int> dir, vector<pii> pos) {
    for(int i = 1; i <= 16; i++) {
        int x = pos[i].first;
        int y = pos[i].second;
        if(x == -1) continue;

        for(int k = 0; k < 8; i++) {
            int nd = dir[i] + k;
            if(nd == 9) nd = 1;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if(mp[nx][ny] == -1) continue;
            dir[i] = nd;
            if(mp[nx][ny] != 0) {
                swap(mp[nx][ny], mp[x][y]);
                swap(pos[mp[nx][ny]], pos[mp[x][y]]);
            }
            break;
        }
    }
}

int go(int x, int y, int dir, vector<vector<int>> mp, vector<int> dir, vector<pii> pos) { 

    int ret = 0;
    bool ok = false;
    

}

int main() {
    fastio;

    vector<vector<int>> mp(4, vector<int>(4));
    vector<pii> pos(17);
    vector<int> dir(17);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> mp[i][j] >> dir[mp[i][j]];
            pos[mp[i][j]] = {i, j};
        }
    }
    
    
    int ans = mp[0][0];
    int ds = dir[mp[0][0]];

    pos[mp[0][0]] = {-1, -1};
    mp[0][0] = -1;

    int tmp = go(0, 0, ds, mp, dir, pos);
    cout << ans + tmp << '\n';

    return 0;
}