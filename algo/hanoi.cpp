#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ull = unsigned long long;
void go(int n, ull k, int st, int by, int to) {
    cout << n << ' ' << k << ' ' << st << ' ' << by << ' ' << to << '\n';
    if(k == 0) {
        cout << st << ' ' << to << '\n';
        return ;
    }

    if(k > (1 << (n - 1))) {
        go(n - 1, k - (1 << (n - 1)), by, st, to);
    } else {
        go(n - 1, k, st, to, by);
    }
}
    
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; ull k;
        cin >> n >> k;
        k--;
        go(n, k, 1, 2, 3);
    }
    return 0;
}