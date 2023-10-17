#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a, b, k, x;
    cin >> a >> b >> k >> x;
    int cnt = 0;
    for(int i = a; i <= b; i++) {
        if(abs(i - k) <= x) cnt++;
    }
    
    if(cnt == 0) cout << "IMPOSSIBLE" << '\n';
    else cout << cnt << '\n';
    return 0;
}