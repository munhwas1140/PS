#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100001];
bool visited[100001], finished[100001];
int cnt;
void DFS(int now) {
    visited[now] = true;
    int next = a[now];
    if(visited[next]) {
        if(!finished[next]) {
            for(; next != now; next = a[next]) cnt++;
            cnt++;
        }
    } else DFS(next);
    finished[now] = true;
    return ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        memset(visited,false,sizeof(visited));
        memset(finished,false,sizeof(finished));
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cnt = 0;        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) DFS(i);
        }
        cout << n - cnt << '\n';
    }     
    return 0;
}