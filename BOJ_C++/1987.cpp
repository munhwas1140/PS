#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m;
vector<string> a;
vector<bool> check(26, false);
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int go(int x, int y) {
    
    int ret = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        int next = a[nx][ny] - 'A';
        if(!check[next]) {
            check[next] = true;
            ret = max(ret,go(nx,ny) + 1);
            check[next] = false;
        }
    } 
    return ret;
}
int main() {
    fastio;
    cin >> n >> m; 
    a.resize(n);
    for(auto &s : a) cin >> s;
    check[a[0][0] - 'A'] = true;
    cout << go(0,0) << '\n';
    return 0;
}