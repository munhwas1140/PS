#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int psum[200001];
int main() {
    fastio;
    int n; cin >> n;
    vector<tuple<int,int,int>> a(n);
    for(int i = 0; i < n; i++) {
        auto &[s, c, idx] = a[i];
        cin >> c >> s;
        idx = i;
    }

    sort(a.begin(), a.end());
    int sum = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(r < n && get<0>(a[l]) == get<0>(a[r])) r++;
        for(int j = l; j < r; j++) {
            ans[get<2>(a[j])] = sum - psum[get<1>(a[j])];
        }
        for(int j = l; j < r; j++) {
            psum[get<1>(a[j])] += get<0>(a[j]);
            sum += get<0>(a[j]);
        }
        i = r - 1;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
