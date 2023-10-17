#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void hanoi(int k, int s, int e) {
    if(k == 1) {
        cout << s << ' ' << e << '\n';
        return ;
    }

    int empty = 3 - (s + e) % 3;
    hanoi(k - 1, s, empty);
    hanoi(1, s, e);
    hanoi(k - 1, empty, e);
}
int main() {
    fastio;
    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 3);

    return 0;
}