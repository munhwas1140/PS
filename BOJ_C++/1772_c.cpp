#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int k, n;
    cin >> k >> n;

    int tmp = n - k;
    
    int it = 0;
    while( (it * (it + 1)) / 2 <= tmp) it++;
    it--;

    it = min(it, k - 1);
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        a[i] = i + 1;
    }
    int gap = 1;    
    int cnt = 1;
    for(int i = k - it; i < k; i++) {
        a[i] += gap;
        gap += cnt++;
        gap++;
    }

    for(int i = 0; i < k; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}