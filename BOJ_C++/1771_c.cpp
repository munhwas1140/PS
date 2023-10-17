#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> prime;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 1) {
            ++mp[a[i]];
            if(mp[a[i]] > 1) {
                ok = true;
            }

        }
    }

    if(ok) {
        cout << "YES" << '\n';
        return ;
    }

    for(int x : prime) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % x == 0) {
                while(a[i] % x == 0) a[i] /= x;
                cnt++;
            }
            if(cnt > 1) break;
        }
        if(cnt > 1) {
            cout << "YES" << '\n';
            return ;
        }
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != 1) {
            if(a[i] == a[i + 1]) {
                cout << "YES" << '\n';
                return ;
            }
        }
    }
    cout << "NO" << '\n';
    return ;

}
bool check[32000];
int main() {
    for(int i = 2; i < 32000; i++) {
        if(!check[i]) {
            check[i] = true;
            prime.push_back(i);
            for(int j = i + i; j < 32000; j += i) {
                check[j] = true;
            }
        }
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}