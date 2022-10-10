#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
string a[101];
int l[5001];
int r[5001];
int rnum[101][101];
int cnum[101][101];
vector<int> g[5001];
bool visited[5001];
bool dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(r[next] == -1 || !visited[r[next]] && dfs(r[next])) {
            r[next] = now;
            l[now] = next;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ccnt = 0;
    int rcnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '.' && cnum[i][j] == 0) {
                cnum[i][j] = ++ccnt;
                int nx = i + 1;
                int ny = j;
                while(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == '.') {
                    cnum[nx][ny] = ccnt;
                    nx++;
                }
            }
            if(a[i][j] == '.' && rnum[i][j] == 0) {
                rnum[i][j] = ++rcnt;
                g[rcnt].push_back(cnum[i][j]);
                int nx = i;
                int ny = j + 1;
                while(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == '.') {
                    rnum[nx][ny] = rcnt;
                    ny++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '.') {
                g[rnum[i][j]].push_back(cnum[i][j]);
            }
        }
    }
 
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    int ans = 0;
    for(int i = 1; i <= rcnt; i++) {
        if(l[i] == -1) {
            memset(visited,false,sizeof(visited));
            if(dfs(i)) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}