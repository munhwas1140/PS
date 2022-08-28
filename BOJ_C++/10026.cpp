#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void BFS(vector<string> &a) {
    int cnt = 0;
    bool visited[100][100] = {false,};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                cnt += 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()) {
                    auto &[x, y] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(a[x][y] == a[nx][ny] && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout << cnt << ' ';
}

int main() {
    fastio;
    cin >> n;
    vector<string> a(n);
    for(string &x : a) cin >> x;
    BFS(a);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'R') a[i][j] = 'G';
        }
    }
    BFS(a);
    return 0;
}