#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
vector<int> ans;
void go(int now, int prev) {
    for(int i = 1; i <= n; i++) {
        if(prev == now) {
            
        } else {

        }
    }
    ans.push_back(now);
}
int main() {
    fastio;
    cin >> n;
    go(1, -1);
    return 0;
}