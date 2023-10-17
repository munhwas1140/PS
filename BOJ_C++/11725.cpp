#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
vector<int> g[100001];
bool visited[100001];
int p[100001];
void go(int now) {
    
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) {
            p[next] = now;
            go(next);
        }
    }
}
int main() {
    fastio;
    cin >> n; 
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    go(1);
    
    for(int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }
    return 0;
}