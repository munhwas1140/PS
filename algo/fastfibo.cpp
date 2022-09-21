#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
void mul(int a[2][2], int b[2][2]) {
    int c[2][2] = {{0, 0}, {0, 0}};
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 1000;
            }
        }
    }
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) a[i][j] = c[i][j];
    }
    return ;
}
void fibo(int a[2][2], int n) {
    if(n == 0 || n == 1) return ;
    int tmp[2][2] = {{1, 1}, {1, 0}};
    fibo(a, n / 2);
    mul(a, a);
    if(n % 2) mul(a, tmp);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int a[2][2] = {{1,1},{1,0}};
        int n; cin >> n;
        if(n == 0) cout << 0 << '\n';
        else {
            fibo(a, n - 1);
            cout << a[0][0] << '\n';
        }
    }

    return 0;
}