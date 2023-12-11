#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(1001, vector<int>(1001));
    
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x2][y2]++;
        a[x1][y2]--;
        a[x2][y1]--;
    }

    for(int i = 0; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            a[i][j] += a[i][j - 1];
        }
    }

    for(int j = 0; j <= 1000; j++) {
        for(int i = 1; i <= 1000; i++) {
            a[i][j] += a[i - 1][j];
        }
    }

    int ans = 0;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            if(a[i][j] == k) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}