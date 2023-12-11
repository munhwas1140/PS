#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<tuple<int,int,int>> a;
vector<vector<int>> dp;
int n;
set<int> st;
int go(int now, int k) {
    if(now == 2 * n || k == 0) return 0;
    
    int &ret = dp[now][k];
    if(ret != -1) return ret;

    auto &[pos, f, idx] = a[now];
    
    int tmp = st.size();
    if(f == 1) {
        st.insert(idx);
        tmp++;
    } else {
        if(st.count(idx)) st.erase(idx);
    }
    
    ret = go(now + 1, k);
    
    set<int> tst(st);
    st.clear();

    ret = max(ret, tmp + go(now + 1, k - 1));
    st = set<int>(tst);
    return ret;
}
int main() {
    fastio;
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        a.push_back(make_tuple(s, 1, i));
        a.push_back(make_tuple(e, -1, i));
    }

    sort(a.begin(), a.end());
    dp = vector<vector<int>>(2 * n, vector<int>(k + 1, -1));
    cout << go(0, k) << '\n';

    return 0;
}