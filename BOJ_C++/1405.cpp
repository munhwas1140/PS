#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<pair<int,int>> dir;
int n;
double p[4];
bool visited[30][30];
vector<int> tmp;
double ans = 0; 
void go(int x, int y, double now, int c) {
    if(c == n)  {
        ans += now;
        return ;
    }
    for(int i = 0; i < 4; i++) {
        if(p[i] == 0) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        tmp.push_back(i);
        if(!visited[nx][ny]) {
            visited[nx][ny] = true;
            go(nx, ny, now * p[i], c + 1);
            visited[nx][ny] = false;
        }
        tmp.pop_back();
    }
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < 4; i++) {
        cin >> p[i];
        p[i] /= 100.0;
    } 

    visited[15][15] = true;
      
    go(15,15,1.0,0);
    
    cout << fixed << setprecision(12);
    cout << ans << '\n';
    return 0;
}