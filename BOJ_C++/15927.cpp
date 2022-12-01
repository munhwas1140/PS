#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int m[26];
int M[26];
int a[500000];
int main() {
    fastio;
    string str; cin >> str;
    int n = str.size();
    memset(m, -1,sizeof(m));

    for(int i = 0; i < n; i++) {
        int now = str[i] - 'A';
        a[i] = now;
        if(m[now] == -1) m[now] = i;
        M[now] = max(M[now], i);
    }

    int ans = -1;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j || m[i] == -1 || m[j] == -1 || M[j] < m[i]) continue;
            ans = max(ans, M[j] - m[i] + 1);
        }
    }
    cout << ans << '\n';
    ABCABCACBACBA
    return 0;
}