#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;

    int now; cin >> now;
    priority_queue<int> pq;
    for(int i = 0; i < n - 1; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    int ans = 0;
    while(!pq.empty() && pq.top() >= now) {
        now++;
        ans++;
        pq.push(pq.top() - 1);
        pq.pop();
    }
    cout << ans << '\n';

    return 0;
}