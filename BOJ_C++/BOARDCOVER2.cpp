#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<vector<pair<int,int>>> rotations;
int blockSize;
int r, c, n, m;
vector<string> rotate(const vector<string> &arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[0].size(); j++) {
            ret[j][arr.size() - i - 1] = arr[i][j];
        }
    }
    return ret;
}
void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);

    for(int rot = 0; rot < 4; rot++) {
        int oriX = -1, oriY = -1;
        for(int i = 0; i < block.size(); i++) {
            for(int j = 0; j < block[0].size(); j++) {
                if(block[i][j] == '#') {
                    if(oriX == -1) {
                        oriX = i;
                        oriY = j;
                    }
                    rotations[rot].push_back(make_pair(i - oriX, j - oriY));
                }
            }
        }
        block = rotate(block);
    }
    
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();
}
int coverd[10][10];
int best;
bool Set(int x, int y, const vector<pair<int,int>> &block, int delta) {
    bool flag = true;
    for(int i = 0; i < block.size(); i++) {
        int nx = x + block[i].first;
        int ny = y + block[i].second;
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) return false;
        if(delta == 1 && coverd[nx][ny] == 1) return false;
        if(delta == -1 && coverd[nx][ny] == 0) return false;
    }

    for(int i = 0; i < block.size(); i++) {
        int nx = x + block[i].first;
        int ny = y + block[i].second;
        coverd[nx][ny] += delta;
    }
    return true;
}

void search(int placed) {
    int x = -1, y = -1;
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(coverd[i][j] == 0) {
                if(y == -1) {
                    x = i; y = j;
                }
                cnt++;
            }
        }
    }

    int k = cnt / blockSize;
    if(placed + k <= best) return ;

    if(y == -1) {
        best = max(best, placed);
        return ;
    }

    for(int i = 0; i < rotations.size(); i++) {
        if(Set(x, y, rotations[i], 1)) {
            search(placed + 1);
        }
        Set(x, y, rotations[i], -1);
    }
    coverd[x][y] = 1;
    search(placed);
    coverd[x][y] = 0;
}
void solve() {
    cin >> r >> c >> n >> m;
    vector<string> tmp(r);
    vector<string> block(n);
    for(int i = 0; i < r; i++) cin >> tmp[i];
    for(int i = 0; i < n; i++) cin >> block[i];
    generateRotations(block);

    memset(coverd,0,sizeof(coverd));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(tmp[i][j] == '#') coverd[i][j] = 1;
        }
    }
    best = 0;
    search(0);
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