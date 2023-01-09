#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[50][50];
int it, tmp;
void go(int s, int now) {
    if(now == 1) {
        a[s][s] = it;
        return ;
    }
    if(now <= 0) return;
    
    for(int i = s; i < s + now; i++) {
        a[s][i] = it;
        it += tmp;
        if(tmp > 0) {
            tmp -= 1;
            tmp *= -1;
        } else {
            tmp += 1;
            tmp *= -1;
        }
    }

    for(int i = s + 1; i < s + now; i++) {
        a[i][s + now - 1] = it;
        it += tmp;
        if(tmp > 0) {
            tmp -= 1;
            tmp *= -1;
        } else {
            tmp += 1;
            tmp *= -1;
        }
    }

    for(int i = s + now - 2 ; i >= s; i--) {
        a[s + now - 1][i] = it;
        it += tmp;
        if(tmp > 0) {
            tmp -= 1;
            tmp *= -1;
        } else {
            tmp += 1;
            tmp *= -1;
        }
    }

    for(int i = s + now - 2; i >= s + 1; i--) {
        a[i][s] = it;
        it += tmp;
        if(tmp > 0) {
            tmp -= 1;
            tmp *= -1;
        } else {
            tmp += 1;
            tmp *= -1;
        }
    }

    go(s + 1, now - 2);
}
void solve() {
    cin >> n;
    it = 1, tmp = n * n - 1;
    go(0, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}