#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, l;
    cin >> n >> l;
    deque<pii> dq;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        while(!dq.empty() && dq.back().first > x) dq.pop_back();
        dq.push_back({x, i});
        while(!dq.empty() && dq.front().second <= i - l) dq.pop_front();
        cout << dq.front().first << ' ';
    }
    cout << '\n';

    return 0;
}