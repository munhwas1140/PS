#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    deque<ll> dq;
    dq.push_back(a[0]);
    int l = 1, r = n - 1;
    while(l <= r) {
        dq.push_front(a[r--]);
        if(l > r) break;
        dq.push_back(a[r--]);
        dq.push_front(a[l++]);
        if(l > r) break;
        dq.push_back(a[l++]);
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += abs(dq[i] - dq[i + 1]);
    }

    dq = deque<ll>();
    l = 0, r = n - 2;
    dq.push_back(a[n - 1]);
    while(l <= r) {
        dq.push_front(a[l++]);
        if(l > r) break;
        dq.push_back(a[l++]);
        dq.push_front(a[r--]);
        if(l > r) break;
        dq.push_back(a[r--]);
    }

    ll tmp = 0;
    for(int i = 0; i < n - 1; i++) {
        tmp += abs(dq[i] - dq[i + 1]);
    }
    cout << max(ans, tmp) << '\n';
    return 0;
}