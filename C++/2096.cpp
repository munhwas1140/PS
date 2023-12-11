#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int mx[2][3], mn[2][3], a[3];
int n;
int main() {
    fastio;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
         for(int j = 0; j < 3; j++) {
            cin >> a[j];
            int prev = (i % 2) ^ 1;
            mx[i%2][j] = max(mx[prev][j], (j == 1) ? max(mx[prev][j + 1], mx[prev][j - 1]) : mx[prev][1]) + a[j];
            mn[i%2][j] = min(mn[prev][j], (j == 1) ? min(mn[prev][j + 1], mn[prev][j - 1]) : mn[prev][1]) + a[j];
        }
    }     
    int x = (n - 1) % 2;
    int a = mx[x][0], b = mn[x][0];
    for(int i = 1; i <= 2; i++) {
        a = max(a, mx[x][i]);
        b = min(b, mn[x][i]);
    }
    cout << a << ' ' << b << '\n';
    return 0;
}