#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int f(int n) {
    if(n == 0) return 1;
    int ret = n * f(n - 1);
    while(ret % 10 == 0) ret /= 10;
    ret %= 1000;
    return ret;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}