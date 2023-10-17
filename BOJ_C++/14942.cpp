#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
int a[100001];
int p[100001][20];
int distp[100001][20];
bool visited[100001];
vector<pair<int,int>> g[100001];
void DFS(int now) {
    visited[now] = true;
    for(auto &next : g[now]) {
        if(!visited[next.first]) {
            p[next.first][0] = now;
            distp[next.first][0] = next.second;
            DFS(next.first);
        }
    } 
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j < 20; j++) {
            distp[i][j] = 1e9;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }

    DFS(1);
    

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            p[j][i] = p[p[j][i-1]][i-1];
            distp[j][i] = distp[p[j][i-1]][i-1] + distp[j][i-1];
        }
    }

    for(int i = 1; i <= n; i++) {
        int now = i;
        int st = a[i];
        for(int j = 19; j >= 0; j--) {
            if(distp[now][j] <= st) {
                st -= distp[now][j];
                now = p[now][j];
            }
        }
        cout << now << '\n';
    }
      
    return 0;
}