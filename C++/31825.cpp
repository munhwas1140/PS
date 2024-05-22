#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            cout << query(1, 1, n, l, r) << '\n';
        } else {
            update(l, r);
        }
    }
    return 0;
}

// 0 == 1
// 1 => 26번
// 0 == 1
// 내부는 안 번함
// A A A A B B
// A B A A B B
// A C A A B B
// ..
// A A A A B B
// l++, r++

1, -1