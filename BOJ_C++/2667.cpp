#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }     
    int cnt = 0;
    vector<int> ans; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '1') {
                cnt += 1; 
                int num = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                a[i][j] = '0';
                while(!q.empty()) {
                    auto &[x, y] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(a[nx][ny] == '1') {
                            a[nx][ny] = '0';
                            num += 1;
                            q.push({nx,ny});
                        }
                    }
                }
                ans.push_back(num);
            }
        }
    }
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for(int &x : ans) cout << x << '\n';
      
    return 0;
}