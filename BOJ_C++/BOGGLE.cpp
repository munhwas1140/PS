#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool dp[5][5][10];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int f(vector<string> &a, string str) {
    memset(dp,false,sizeof(dp));
    for(int idx = 0; idx < str.size(); idx++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(a[i][j] == str[idx]) {
                    if(idx == 0) {
                        dp[i][j][idx] = true;
                    } else {
                        for(int k = 0; k < 8; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                            if(dp[nx][ny][idx - 1]) {
                                dp[i][j][idx] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(dp[i][j][str.size() - 1]) return 1;
        }
    }
    return 0;
}
void solve() {
    vector<string> a(5);
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        string str; cin >> str;
        int ans = f(a, str);
        cout << str << ' ' << (ans ? "YES" : "NO") << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}