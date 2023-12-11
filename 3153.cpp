#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, SN;
vector<string> a;
vector<pii> tower;

vector<int> g[40001], gp[40001], SCCv[40001], order;
bool visited[40001];
int Map[100][100], SCC[40001];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int neg(int now) {
    if(now == 0) return 1;
    if(now == 1) return 0;
    if(now == 2) return 3;
    if(now == 3) return 2;
    return -1;
}

void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCCv[num].push_back(now);
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int main() {
    fastio;
    cin >> n >> m;
    a.resize(n);
    memset(Map, -1, sizeof(Map));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'T') {
                Map[i][j] = tower.size();
                tower.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'n') {
                vector<pii> pos;
                
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    while(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if(a[nx][ny] == '#') break;
                        if(a[nx][ny] == 'T') {
                            pos.push_back({Map[nx][ny], neg(k)});
                            break;
                        }
                        nx += dx[k];
                        ny += dy[k];
                    }
                }
                cout << "POS " << '\n';
                for(int i = 0; i < pos.size(); i++) {
                    cout << pos[i].first << ' ' << pos[i].second << '\n';
                }
                if(pos.size() == 1) {
                    // 무조건
                    int TN = pos[0].first;
                    int dir = pos[0].second;
                    
                    int x = 4 * TN + dir;
                    int nx = 4 * TN + neg(dir); 
                    // (x v x)
                    g[nx].push_back(x);
                    g[nx].push_back(x);
                    gp[x].push_back(nx);
                    gp[x].push_back(nx);
                } else if(pos.size() == 2) {
                    //둘 중 한개만
                    int t1 = pos[0].first, t2 = pos[1].first;
                    int dir1 = pos[0].second, dir2 = pos[1].second;

                    int x = 4 * t1 + dir1, nx = 4 * t1 + neg(dir1);
                    int y = 4 * t2 + dir2, ny = 4 * t2 + neg(dir2);

                    // (x v y) ^ (~x v ~y);
                    g[nx].push_back(y);
                    g[ny].push_back(x);
                    g[x].push_back(ny);
                    g[y].push_back(nx);

                    gp[nx].push_back(y);
                    gp[ny].push_back(x);
                    gp[x].push_back(ny);
                    gp[y].push_back(nx);
                } else if(pos.size() == 3) {
                    //마주보는 두 개 빼고 한가지는 무조건
                    //마주보는것들은 무조건 반대 방향으로
                    int sum = 0;
                    for(int i = 0; i < 3; i++) {
                        sum += pos[i].second;
                    }

                    int tar = -1;
                    if(sum == 3) tar = 2;
                    if(sum == 4) tar = 3;
                    if(sum == 5) tar = 0;
                    if(sum == 6) tar = 1;

                    int a, b, x, na, nb, nx;
                    a = b = x = na = nb = nx = -1;
                    for(auto [TN, dir] : pos) {
                        if(dir == tar) {
                            x = 4 * TN + dir;
                            nx = 4 * TN + neg(dir);
                        } else {
                            if(a == -1) {
                                a = 4 * TN + dir;
                                na = 4 * TN + neg(dir);
                            } else {
                                b = 4 * TN + dir;
                                nb = 4 * TN + neg(dir);
                            }
                        }
                    }

                    // (x v x)
                    g[nx].push_back(x);
                    g[nx].push_back(x);
                    gp[x].push_back(nx);
                    gp[x].push_back(nx); 
                    
                    // (~a v ~a)
                    g[a].push_back(na);
                    g[a].push_back(na);
                    gp[na].push_back(a);
                    gp[na].push_back(a);

                    // (~b v ~b)
                    g[b].push_back(nb);
                    g[b].push_back(nb);
                    gp[nb].push_back(b);
                    gp[nb].push_back(b);
                } //항상 정답이 존재하는 경우만 주어지기 떄문에 4개는 없음
                
                
            }
        }
    }
    

    for(int i = 0; i < 4 * (int)tower.size(); i++) {
        if(!visited[i]) dfs(i);
    }
    
    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());
    
    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++SN);
    }

    vector<int> ans(2 * (int)tower.size(), -1);
    for(int i = 1; i <= SN; i++) {
        for(int x : SCCv[i]) {
            if(ans[x / 2] == -1) {
                ans[x / 2] = !(x % 2);
            }
        }
    }

    for(int i = 0; i < (int)tower.size(); i++) {
        char x = ' ';
        if(ans[2 * i] == 1) {
            if(ans[2 * i + 1] == 1) {
                x = '1';
            } else {
                x = '2';
            }
        } else {
            if(ans[2 * i + 1] == 1) {
                x = '4';
            } else {
                x = '3';
            }
        }
        a[tower[i].first][tower[i].second] = x;
    }
    cout << '\n' << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}