#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[101];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    

    return 0;
}