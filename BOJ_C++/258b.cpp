#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
vector<string> a;
set<string> st;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
bool visited[11][11];
int main() {
    fastio;
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    ll ans = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < 8; k++) {
                int x = i, y = j;
                ll tmp = a[x][y] - '0';
                for(int asdf = 0; asdf < n - 1; asdf++) {
                    x += dx[k];
                    y += dy[k];
                    
                    if(x == 0) x = n;
                    else if(x == n + 1) x = 1;
                    if(y == 0) y = n;
                    else if(y == n + 1) y = 1;

                    tmp *= 10;
                    tmp += a[x][y] - '0';
                }
                if(tmp > ans) ans = tmp;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}