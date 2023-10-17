#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1);
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }

    for(int i = 1; i < x; i++) {
        if(cnt[i] % (i + 1)) {
            cout << "No" << '\n';
            return 0;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
    }
    cout << "Yes" << '\n';
    return 0;
}