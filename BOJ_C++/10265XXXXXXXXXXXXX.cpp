#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, k;
int a[1001];
bool visited[1001];
bool check[1001];
int cnt;

int DFS(int now) {
    visited[now] = true;
    int ret = 1;
    
    int next = a[now];
    if(!visited[next]) {
        ret += DFS(next);
    } else {
        if(!check[next]) {
            for(; next != now; next = a[next]) cnt++;
            cnt++;
        }
    }
    check[now] = true;
    return ret;
}
int main() {
    fastio;
    cin >> n >> k; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    
    vector<pair<int,int>> pos;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt = 0;
            int x = DFS(i);
            pos.push_back(make_pair(cnt, x)); 
        } 
    }
    for(auto p : pos) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}