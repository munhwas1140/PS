#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    string str; cin >> str;
    bool ok = false;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'S') ans++;
        else {
            ans++;
            if(!ok) ok = true;
            i++;
        }
    }
    cout << ans + ok << '\n';

    return 0;
}