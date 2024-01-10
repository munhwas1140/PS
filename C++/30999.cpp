#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(str[j] == 'O') cnt++;
        }
        if(cnt > m / 2) ans++;
    }
    cout << ans << '\n';
    return 0;
}