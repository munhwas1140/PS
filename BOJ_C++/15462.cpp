#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> visited(n + 1), finished(n + 1);
    int ans = 0;
    function<void(int)> check = [&] (int now) {
        visited[now] = true;
        int next = a[now];
        if(!visited[next]) {
            check(next);
        } else {
            if(!finished[next]) {
                for(int i = next; i != now; i = a[i]) {
                    ans++;
                }
                ans++;
            }
        }
        finished[now] = true;
        return ;
    };

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            check(i);
        }
    }
    cout << ans << '\n';

    return 0;
}