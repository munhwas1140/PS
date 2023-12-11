#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    vector<string> b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int now = i;
        for(int j = 0; j < 3; j++) {
            now = pos[now];
        }
        cout << b[now] << '\n';
    }

    return 0;
}