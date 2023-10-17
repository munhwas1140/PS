#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
map<int,int> dp;
int go(int now) {
    if(now == 0) return 0;
    if(!dp.count(now)) return dp[now];


    dp = go(now - 1);
}
int main() {
    fastio;
    cin >> n;
    cout << go(n) << '\n';


    return 0;
}