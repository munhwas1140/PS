#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n;
ll x;
ll a[100000];

ll go(int mid) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < mid; i++) {
        pq.push(0LL);
    }

    for (int i = 0; i < n; i++) {
        pq.push(pq.top() + a[i]);
        pq.pop();
    }
    while (pq.size() != 1) {
        pq.pop();
    }
    return pq.top();
}

int main() {
    fastio;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = 1, e = n;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (go(mid) <= x) {
            e = mid - 1;
            ans = mid;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}