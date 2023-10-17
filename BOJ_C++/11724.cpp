#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a[1001];
bool visited[1001];
void DFS(int now) {
    visited[now] = true;
    for(int &next : a[now]) {
        if(!visited[next]) DFS(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }      
      
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt += 1;
            DFS(i);    
        }
    }
    cout << cnt << '\n';
    return 0;
}