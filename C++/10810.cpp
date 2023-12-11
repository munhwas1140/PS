#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int check[101];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        for(int j = s; j <= e; j++) {
            check[j] = d;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << check[i] << ' ';
    }
    cout << '\n';

    return 0;
}