#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
ll query(int x1, int y1, int x2, int y2) {
    int t1 = max(x1, y1);
    
    int t2 = max(x2, y2);

}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    }

    cin >> m;
    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }
    return 0;
}