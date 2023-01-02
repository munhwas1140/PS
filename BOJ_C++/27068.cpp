#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    fastio;
    int n, m, k;
    ll x;
    cin >> n >> m >> k >> x;
    
    vector<vector<ll>> a(n, vector<ll>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    function<int(vector<vector<ll>>, ll)> go = [&] (vector<vector<ll>> mp, ll mid) {
        int ret = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pii> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j] >= x - mid) continue;
                else {
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(abs(mp[nx][ny] - mp[i][j]) > mid) {
                            visited[i][j] = true;
                            q.push({i, j});
                            break;
                        }
                    }
                }
                
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            ret++;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(mp[nx][ny] < x - mid && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return ret;
    };


    ll s = 0, e = x;
    ll ans = x;
    while(s <= e) {
        ll mid = (s + e) / 2;
        if(go(a, mid) <= k) {
            ans = mid;
            e = mid - 1;
        } else s = mid + 1;
    }
    cout << ans << '\n';

    


    return 0;
}