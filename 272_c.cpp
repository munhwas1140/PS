#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> even, odd;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp % 2) odd.push_back(tmp);
        else even.push_back(tmp);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int t1 = -1;
    if(odd.size() >= 2) {
        int x = odd.size();
        t1 = odd[x - 1] + odd[x - 2];
    }

    int t2 = -1;
    if(even.size() >= 2) {
        int x = even.size();
        t2 = even[x - 1] + even[x - 2];
    }

    cout << max(t1, t2) << '\n';

    return 0;
}