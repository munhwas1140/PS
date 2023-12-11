#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[100][100];
int b[100][100];
int c[100][100];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int k;
    cin >> m >> k;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    for(int z = 0; z < m; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < k; y++) {
                c[x][y] += a[x][z] * b[z][y];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}