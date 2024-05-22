#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<int> tmp;
        for(int j = 0; j < 8; j++) {
            if(x & (1 << j)) tmp.push_back(j);
        }
        if(tmp.size() == 2) {
            swap(a[tmp[0]], a[tmp[1]]);
        }
    }

    int k; cin >> k;
    cout << a[k] << '\n';

    return 0;
}
