#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
ll a[100001];
ll pSum[100001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pSum[i + 1] = pSum[i] + a[i];
    }


    return 0;
}