#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt = 0;
void Merge(vector<int> &a, int s, int m, int e) {
    int tmp[10001];
    for(int i = s; i <= e; i++) {
        tmp[i] = a[i];
    }
    
    int i, k, j;
    i = k = s;
    j = m + 1;
    while(i <= m && j <= e) {
        if(++cnt && tmp[i] <= tmp[j]) {
            a[k++] = tmp[i++];
        } else {
            a[k++] = tmp[j++];
        }
    }
    while(i <= m) {
        a[k++] = tmp[i++];
    }
    while(j <= e) {
        a[k++] = tmp[j++];
    }
}
void Sort(vector<int> &a, int n) {
    int sz = 1;
    while(sz < n) {
        for(int i = 0; i < n; i += 2 * sz) {
            int low = i;
            int mid = min(low + sz - 1, n - 1);
            int high = min(low + 2 * sz - 1, n - 1);
            Merge(a, low, mid, high);
        }
        sz *= 2;
    }
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cnt = 0;
    Sort(a, n);
    cout << cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}