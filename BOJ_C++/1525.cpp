#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    fastio;
    string start = "";
    for(int i = 0; i < 9; i++) {
        char tmp; cin >> tmp;
        start += tmp;
    }
    
    string end = "123456780";

    map<string, int> m;
    m[start] = 0;
    queue<string> q;
    q.push(start);
    while(!q.empty()) {
        string now = q.front();
        q.pop();
 
        if(now == end) break;
        int d = m[now];    
        int idx = now.find('0');
        int x = idx / 3;
        int y = idx % 3;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            swap(now[idx], now[nx * 3 + ny]);
            if(m.find(now) == m.end()) {
                m[now] = d + 1;
                q.push(now);
            }
            swap(now[idx], now[nx * 3 + ny]);
        }
    }
    

    if(m.find(end) == m.end()) cout << -1 << '\n';
    else cout << m[end] << '\n';
    return 0;
}