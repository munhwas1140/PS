#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
struct asdf {
    int first, second, idx;
};
int main() {
    fastio;
    cin >> n >> m;
    vector<asdf> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].idx = i + 1;
    }

    sort(a.begin(), a.end(), [](auto &t1, auto &t2) {
        if(t1.second == t2.second) {
            if(t1.first == t2.first) {
                return t1.idx < t2.idx;
            }
            return t1.first < t2.first;
        }
        return t1.second < t2.second;
    });

    int cnt = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i].first == 0) continue;
        cnt++;
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[i].second == 0) continue;
        cnt++;
    }

    cout << cnt << '\n';
    
    for(int i = n - 2; i >= 0; i--) {
        if(a[i].first == 0) continue;
        cout << "+ " << a[n - 1].idx << ' ' << a[i].first << '\n';
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[i].second == 0) continue;
        cout << "+ " << a[i].idx << ' ' << a[i].second << '\n';
    }

    return 0;
}