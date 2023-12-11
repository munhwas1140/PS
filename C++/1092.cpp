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
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int m; cin >> m;
    vector<int> b(m);
    for(int &x : b) cin >> x;
    sort(b.begin(), b.end());

    if(a[n - 1] < b[m - 1]) {
        return !(cout << -1 << '\n');
    }
    
    vector<int> cnt(n);
    int idx = 0;
    for(int i = 0; i < m; i++) {
        while(idx < n && b[i] > a[idx]) {
            idx++;
            cnt[idx] = cnt[idx - 1];
        }
        cnt[idx]++;
    }

    for(int i = idx + 1; i < n; i++) {
        cnt[i] = cnt[i - 1];
    }
    vector<int> diff(n);
    for(int i = 0; i < n; i++) {
        diff[i] = cnt[i] - (i - 1 >= 0 ? cnt[i - 1] : 0);
    }


    int c = 0;
    for(int t = 1; ;t++) {
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                if(diff[j]) {
                    diff[j]--;
                    c++;
                    break;
                }
            }
        }
        if(c == m) {
            cout << t << '\n';
            return 0;
        }
    }

    return 0;
}