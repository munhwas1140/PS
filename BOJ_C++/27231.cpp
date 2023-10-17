#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string str;
ll n, num;
ll a[10], cnt[10];
void solve() {
    cin >> str;
    n = str.size();
    num = stoi(str);
    memset(cnt, 0, sizeof(cnt));
    bool ok = true;
    for(int i = 0; i < n; i++) {
        a[i] = str[i] - '0';
        cnt[a[i]]++;
        if(a[i] >= 2) ok = false;
    }

    if(ok) {
        cout << "Hello, BOJ 2023!" << '\n';
        return ;
    }

    int sz = 1 << (n - 1);
    set<int> st;
    
    int ans = 0;
    for(ll i = 0; ; i++) {
        ll tmp = 0;
        for(ll j = 1; j <= 9; j++) {
            tmp += pow(j, i) * cnt[j];
        }
        st.insert(tmp);
        if(tmp > num) break;
    }


    for(int i = 0; i < sz; i++) {
        int now = 0, tmp = 0;
        for(int j = 0; j < n; j++) {
            tmp *= 10;
            tmp += a[j];
            if(i & (1 << j)) {
                now += tmp;
                tmp = 0;
            }
        } 
        now += tmp;
        if(st.count(now)) {
            st.erase(now);
            ans++;
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}