#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
char st[] = {'>','<','v','^'};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int num;
int cnt = 0;
bool check;
void dfs(vector<string> &a, int x, int y, int pre) {

    cnt++;
    int nd = -1;
    if(a[x][y] == 'b') {
        if(pre == 2) nd = 0;
        else nd = 3;
    } else if(a[x][y] == 'd') {
        if(pre == 0) nd = 3;
        else nd = 1;
    } else if(a[x][y] == 'p') {
        if(pre == 1) nd = 2;
        else nd = 0;
    } else if(a[x][y] == 'q') {
        if(pre == 0) nd = 2;
        else nd = 1;
    } else if(a[x][y] == '-') {
        if(pre == 0) nd = 1;
        else nd = 0;
    } else if(a[x][y] == 'l') {
        if(pre == 3) nd = 2;
        else nd = 3;
    }

    if(nd != -1) {
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        dfs(a, nx, ny, nd);
        return ;
    }

    for(int i = 0; i < 4; i++) {
        if(a[x][y] == st[i]) {
            if(check) {
                check = false;
                dfs(a, x + dx[i], y + dy[i], i);
                return ;
            } else return ;
        }
    }
}
bool go(vector<string> &tmp, vector<pii> &pos) {
    for(int t1 = 0; t1 < 4; t1++) {
        for(int t2 = 0; t2 < 4; t2++) {
            bool ok = true;
            vector<string> a = tmp;
            a[pos[0].first][pos[0].second] = st[t1];
            a[pos[1].first][pos[1].second] = st[t2];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(a[i][j] == '*') {
                        if(i - 1 >= 0) {
                            if(a[i - 1][j] == 'p' || a[i - 1][j] == 'q' || a[i - 1][j] == 'l' || a[i - 1][j] == 'v') ok = false;
                        }
                        if(j - 1 >= 0) {
                            if(a[i][j - 1] == 'p' || a[i][j - 1] == 'b' || a[i][j - 1] == '-' || a[i][j - 1] == '>') ok = false;
                        }
                    }else if(a[i][j] == 'l') {
                        bool c1, c2;
                        c1 = c2 = false;
                        if(i - 1 >= 0) {
                            if(a[i - 1][j] == 'p' || a[i - 1][j] == 'q' || a[i-1][j] == 'l' || a[i-1][j] == 'v') c1 = true;
                        }
                        if(j - 1 >= 0) {
                            if(a[i][j-1] == 'p' || a[i][j-1] == 'b' || a[i][j-1] == '>' || a[i][j-1] == '-') c2 = true;
                        }
                        if((c1 && c2) || (!c1 && !c2)) {
                            ok = false;
                            break;
                        } else if(c1) {
                            a[i][j] = 'l';
                        } else {
                            a[i][j] = '-';
                        }
                    } else if(a[i][j] == 'q') {
                        bool c1, c2;
                        c1 = c2 = false;
                        if(i - 1 >= 0) {
                            if(a[i - 1][j] == 'p' || a[i - 1][j] == 'q' || a[i-1][j] == 'l' || a[i-1][j] == 'v') c1 = true;
                        }
                        if(j - 1 >= 0) {
                            if(a[i][j-1] == 'p' || a[i][j-1] == 'b' || a[i][j-1] == '>' || a[i][j-1] == '-') c2 = true;
                        }
                        if(c1 && c2) {
                            a[i][j] = 'd';
                        } else if(c1) {
                            a[i][j] = 'b';
                        } else if(c2) {
                            a[i][j] = 'q';
                        } else {
                            a[i][j] = 'p';
                        }
                    } 
                    if(!ok) break;
                }
                if(!ok) break;
            }

            for(auto [x, y] : pos) {
                cnt = 0;
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(k == 0) {
                        if(a[nx][ny] == 'd' || a[nx][ny] == 'q' || a[nx][ny] == '-') cnt++;
                    } else if(k == 1) {
                        if(a[nx][ny] == 'b' || a[nx][ny] == 'p' || a[nx][ny] == '-') cnt++;
                    } else if(k == 2) {
                        if(a[nx][ny] == 'd' || a[nx][ny] == 'b' || a[nx][ny] == 'l') cnt++;
                    } else if(k == 3) {
                        if(a[nx][ny] == 'p' || a[nx][ny] == 'q' || a[nx][ny] == 'l') cnt++;
                    }
                }
                if(cnt != 1) ok = false;
                
                if(a[x][y] == '<') {
                    if(y - 1 < 0 || a[x][y - 1] == 'd' || a[x][y - 1] == 'q' || a[x][y - 1] == 'l' || a[x][y - 1] == '*') ok = false;
                    if(y - 1 >= 0 && (a[x][y - 1] == '<' || a[x][y - 1] == '>' || a[x][y - 1] == '^' || a[x][y - 1] == 'v')) ok = false;
                } else if(a[x][y] == '>') {
                    if(y + 1 >= m || a[x][y + 1] == 'b' || a[x][y + 1] == 'p' || a[x][y + 1] == 'l' || a[x][y + 1] == '*') ok = false;
                    if(y + 1 < m && (a[x][y + 1] == '<' || a[x][y + 1] == '>' || a[x][y + 1] == '^' || a[x][y + 1] == 'v')) ok = false;
                } else if(a[x][y] == 'v') {
                    if(x + 1 >= n || a[x + 1][y] == 'p' || a[x + 1][y] == 'q' || a[x + 1][y] == '-' || a[x + 1][y] == '*') ok = false;
                    if(x + 1 < n && (a[x + 1][y] == '<' || a[x + 1][y] == '>' || a[x + 1][y] == '^' || a[x + 1][y] == 'v')) ok = false;
                } else {
                    if(x - 1 < 0 || a[x - 1][y] == 'b' || a[x - 1][y] == 'd' || a[x - 1][y] == '-' || a[x - 1][y] == '*') ok = false;
                    if(x - 1 >= 0 && (a[x - 1][y] == '<' || a[x - 1][y] == '>' || a[x - 1][y] == '^' || a[x - 1][y] == 'v')) ok = false;
                }
            }
            
            
        
            // if(ok) {
            //     cnt = 0;
            //     check = true;
            //     dfs(a, pos[0].first, pos[0].second, -1);
            //     cout << num << ' ' << cnt << '\n';
            //     if(cnt != num) ok = false;
            // }

            if(ok) {
                tmp = a;
                return true;
            }
        }
    }

    return false;
}
void solve() {
    cin >> n >> m;
    num = n * m;
    vector<string> a(n);
    vector<pii> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'O') {
                pos.push_back({i, j});
            } else if(a[i][j] == '*') {
                num--;
            }
        }
    }
    
    bool ok = go(a,pos);
    if(!ok) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << a[i] << '\n';
        }
    }

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}