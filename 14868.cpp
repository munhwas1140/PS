#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, k, cnt = 1;
int a[2000][2000];
int p[100001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    p[y] += p[x];
    if(p[y] == -(cnt - 1)) return true;    
    p[x] = y;
    return false;
}
void go(int x, int y, int num) {
    a[x][y] = num;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(a[nx][ny] == 0) go(nx,ny,num);
    }
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    memset(a,-1,sizeof(a));
    cin >> n >> k;
    queue<pair<int,int>> q;
    for(int i = 0; i < k; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        a[t1][t2] = 0;
        q.push({t1,t2});
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0) {
                go(i, j, cnt++);
            }
        }
    }

    if(cnt == 2) return !(cout << 0 << '\n');
    bool ok = false;
    int ans = 0;
    for(int day = 1; ;day++) {
        int sz = q.size();
        for(int asdf = 0; asdf < sz; asdf++) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(a[nx][ny] == -1) {
                    a[nx][ny] = a[x][y];
                    for(int j = 0; j < 4; j++) {
                        int nxx = nx + dx[j];
                        int nyy = ny + dy[j];
                        if(nxx < 0 || nxx >= n || nyy < 0 || nyy >= n) continue;
                        if(a[nxx][nyy] == -1) continue;
                        if(find(a[nx][ny]) != find(a[nxx][nyy])) {
                            if(set_union(a[nx][ny], a[nxx][nyy])) {
                                ok = true;
                                ans = day;
                                break;
                            }
                        }
                    }
                    q.push({nx,ny});
                } else {
                    if(find(a[nx][ny]) != find(a[x][y])) {
                        if(set_union(a[nx][ny], a[x][y])) {
                            ok = true;
                            ans = day;
                            break;
                        }
                    }
                }
            }
        } 

        if(ok) break;
    }
    
    cout << ans << '\n';
    return 0;
}