#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<int> g[501];
bool visited[501];
int edge, vertex;
void go(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        edge += 1;
        if(!visited[next]) {
            go(next);
        }
    }
    vertex += 1;
}

int main() {
    fastio;
    int cnt = 0;
    while(++cnt) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < 501; i++) {
            g[i].clear();
        }
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                edge = 0; vertex = 0;
                go(i);
                if(vertex - 1 == edge / 2) {
                    ans += 1;
                }
            }
        }
        cout << "Case " << cnt << ": ";
        if(ans == 0) {
            cout << "No trees." << '\n';
        } else if(ans == 1) {
            cout << "There is one tree." << '\n';
        } else {
            cout << "A forest of " << ans << " trees." << '\n';
        }
    }
      
    return 0;
}