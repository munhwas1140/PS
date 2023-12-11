#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string str;
int n;
string a[100];
int dp[101];
int main() {
    fastio;
    cin >> str >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    str = " " + str;
    dp[0] = 1;
    for(int i = 1; i < str.size(); i++) {
        for(int j = 0; j < n; j++) {
            int sz = a[j].size();
            if(sz > i || dp[i - sz] == 0) continue;
            bool ok = true;
            for(int k = 0; k < sz; k++) {
                if(str[i - sz + k + 1] != a[j][k]) ok = false;
            }
            if(ok) dp[i] = true;
        }
    }
    cout << dp[str.size() - 1] << '\n';

    return 0;
}