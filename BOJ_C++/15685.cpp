#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
bool check[101][101];
void go(int x, int y, int d, int g) {
    check[x][y] = true;
    vector<int> v;
    v.push_back(d);
    int s = 0;
    while(g--) {
        for(int i = s; i < v.size(); i++) {
            x += dx[v[i]];
            y += dy[v[i]];
            check[x][y] = true;
        }
        s = v.size();
        for(int i = v.size() - 1; i >= 0; i--) {
            v.push_back((v[i] + 1) % 4);
        }
    }
}
int main() {
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        go(x, y, d, g + 1);
    }

    int ans = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(check[i][j] && check[i+1][j+1] && check[i+1][j] && check[i][j+1]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}