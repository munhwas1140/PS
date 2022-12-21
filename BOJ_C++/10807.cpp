#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, v, cnt;
int main() {
    fastio;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    cin >> v;
    for(int &x : a) if(x == v) cnt++;
    cout << cnt << '\n';

    return 0;
}