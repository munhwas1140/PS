#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos;
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
        if(a[i] % 2) pos.push_back(i);
        if(a[i] % 2 == 0) pos2.push_back(i);
    }

    



    return 0;
}