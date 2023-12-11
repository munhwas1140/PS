#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[] = {0,0,1,-1,0};
int dy[] = {1,-1,0,0,0};
string a[10], b[10];
void togle(int x, int y) {
    for(int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
        if(a[nx][ny] == '#') a[nx][ny] = 'O';
        else a[nx][ny] = '#';
    }
}
int main() {
    fastio;

    for(int i = 0; i < 10; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    int ans = 1e9;

    for(int st = 0; st < (1 << 10); st++) {
        
        for(int i = 0; i < 10; i++) {
            a[i] = b[i];
        }

        int cnt = 0;

        for(int i = 0; i < 10; i++) {
            if(st & (1 << i)) {
                cnt++; togle(0, i);
            }
        }

        for(int i = 1; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(a[i - 1][j] == 'O') {
                    togle(i, j);
                    cnt++;
                }
            }
        }

        for(int i = 0; i < 10; i++) {
            if(a[9][i] == 'O') cnt = 1e9;
        }

        ans = min(ans, cnt);
    }

    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}