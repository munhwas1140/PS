#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
map<string, int> name;
int best;
ll check[50];
ll rSum[51];
int last(ll now) {
    int ret = 0;
    while(now) {
        ret++;
        now /= 2;
    }
    return ret;
}
int chk(ll now, int last) {


}
int go(int idx, ll now) {
    
    int a = chk(now, last(now));
    int next = last(check[idx]);


    go(idx + 1, now);
    go(idx + 1, now | check[idx]);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        name[str] = i;
    }

    memset(check,0,sizeof(check));
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            string str; cin >> str;
            check[i] |= 1 << (name[str]);
        }
    }
    sort(check, check + m, [](ll a, ll b) {
        return a > b;
    });


    for(int i = n - 1; i >= 0; i--) {
        rSum[i] = rSum[i + 1] | check[i];
    }

    best = 1e9;
    cout << go(0, 0); 
    cout << (1 << (n)) - 1 << '\n';;

    

}
int main() {
    cout << last(2) << '\n';
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}