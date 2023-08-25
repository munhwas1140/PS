#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
bool check(int mid, vector<string> &a) {
    set<string> st;
    
    for(int i = 0; i < m; i++) {
        string tmp = a[i].substr(0,mid);
        if(st.count(tmp)) return false;
        st.insert(tmp);
    }
    return true;
}
int main() {
    fastio;
    cin >> n >> m;
    vector<string> a(m);
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < m; j++) {
            a[j] = tmp[j] + a[j];
        }
    }

    int s = 1, e = n;
    int ans = 0;

    while(s <= e) {
        int mid = (s + e) / 2;
        if(check(mid, a)) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }
    cout << n - ans - 1 << '\n';
    return 0;
}