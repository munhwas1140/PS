#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<string> a;
bool visited[100][10];
int n, k;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool bfs(int i, int j) {
    visited[i][j] = true;
    queue<pii> q;
    q.push({i, j});
    int cnt = 0;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= 10) continue;
            if(a[nx][ny] == a[i][j] && visited[nx][ny] == false) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return cnt >= k;
}
void remove(vector<pii> &pos) {
    
    for(auto [i, j] : pos) {
        char tar = a[i][j];
        queue<pii> q;
        q.push({i, j});
        a[i][j] = '0';
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            a[x][y] = '0';
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= 10) continue;
                if(a[nx][ny] == tar) {
                    q.push({nx, ny});
                    a[nx][ny] = '0';
                }
            }
        }
    }
    return ;
}
void down() {
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < 10; j++) {
            if(a[i][j] != '0' && a[i + 1][j] == '0') {
                int x = i + 1;
                int y = j;

                while(x < n && a[x][y] == '0') x++;

                a[x - 1][y] = a[i][j];
                a[i][j] = '0';
            }
        }
    }
}
bool check(void) {
    bool ok = false;
    memset(visited,false,sizeof(visited));
    vector<pii> pos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            if(a[i][j] != '0' && visited[i][j] == false) {
                if(bfs(i, j)) {
                    pos.push_back({i, j});
                    ok = true;
                }
            }
        }
    }
    
    remove(pos);

    down();

    return ok;
}
int main() {
    fastio;
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while(true) {
        if(!check()) break;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }

    return 0;
}