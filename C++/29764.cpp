#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[200001];
int Find(int x) {
    if(p[x] < 0) return x;
    return p[x] = Find(p[x]);
}
void set_union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}
int n, m, q;
int main() {
    fastio;
    cin >> n >> m >> q;

    vector<tuple<int,int,int>> a(n);
    for(int i = 0; i < n; i++) {
        auto &[dist, x, idx] = a[i];
        cin >> dist >> x;
        if(x > m) x %= m;
        idx = i + 1;
    }

    memset(p, -1, sizeof(p));
    sort(a.begin(), a.end());

    vector<int> tmp;
    int now = m;
    for(int i = n - 1; i >= 0; i--) {
        auto &[dist, x, idx] = a[i];
        while(x) {
            if(x > now) {
                x -= now;
                now = 0;
            } else {
                now -= x;
                x = 0;
            }

            tmp.push_back(idx);

            if(now == 0) {
                for(int i = 0; i < (int)tmp.size() - 1; i++) {
                    set_union(tmp[i], tmp[i + 1]);
                }
                tmp = vector<int>();
                now = m;
            }
        }
    }

    for(int i = 0; i < (int)tmp.size() - 1; i++) {
        set_union(tmp[i], tmp[i + 1]);
    }
    

    while(q--) {
        int x, y;
        cin >> x >> y;
        if(Find(x) == Find(y)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}