#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n1, m1, n2, m2;
char a[150][150];
char b[4][50][50];

int check(int i, int j, int dx, int dy) {
    int left_top_x = min(50, i);
    int left_top_y = min(50, j);

    int right_bottom_x = max(50 + n1, i + dx);
    int right_bottom_y = max(50 + m1, j + dy);
    return (right_bottom_x - left_top_x) * (right_bottom_y - left_top_y);
}

int main() {
    fastio;
    cin >> n1 >> m1;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> a[50 + i][50 + j];
        }
    }

    cin >> n2 >> m2;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            cin >> b[0][i][j];
            b[2][n2 - i - 1][m2 - j - 1] = b[0][i][j];
            b[1][m2 - j - 1][i] = b[0][i][j];
            b[3][j][n2 - i - 1] = b[0][i][j];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            for (int k = 0; k < 4; k++) {
                int dx_max = (k % 2 == 0) ? n2 : m2;
                int dy_max = (k % 2 == 0) ? m2 : n2;

                bool f = true;
                for (int dx = 0; dx < dx_max; dx++) {
                    for (int dy = 0; dy < dy_max; dy++) {
                        if (i + dx >= 150 || j + dy >= 150) {
                            f = false;
                            break;
                        }

                        if (b[k][dx][dy] == '1') {
                            if (a[i + dx][j + dy] == '1') {
                                f = false;
                                break;
                            }
                        }
                    }
                }

                if (f) {
                    ans = min(ans, check(i, j, dx_max, dy_max));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}