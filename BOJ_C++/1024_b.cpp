#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int b[5000001];
int main() {
    fastio;
    cin >> n >> m;
    vector<pair<int,int>> a;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        a.push_back({b[i], i});
    }
    sort(a.begin(), a.end());

    int s = 0, e = 1;
    int now = b[a[s].second];
    while(s <= e && e < m) {
        if(now < n) {
            now += b[a[e].second];
            e++;
        } else if(n <= now && now <= 2 * n) {
            break;
        } else if(2 * n < now) {
            now -= b[a[s].second];
            s++;
        }
    }
    cout << e - s << '\n';
    for(int i = s; i < e; i++) {
        cout << a[i].second << '\n';
    }
    return 0;
}