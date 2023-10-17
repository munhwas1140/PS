#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> Slice(const vector<int> &v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}
void print(const vector<int> &pre, const vector<int> &in) {
    const int sz = pre.size();
    if(sz == 0) return ;

    int root = pre[0];
    
    int l = find(in.begin(), in.end(), root) - in.begin();

    print(Slice(pre, 1, l + 1), Slice(in, 0, l));
    print(Slice(pre, l + 1, sz), Slice(in, l + 1, sz));
    cout << root << ' ';
}
void solve() {
    int n; cin >> n;
    vector<int> pre(n), in(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];

    print(pre, in);
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}