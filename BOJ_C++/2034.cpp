#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[10000];
string str = "CXDXEFXGXAXB";
char go(int now, int idx) {
    if(str[now] == 'X') return 'X';
    if(idx == n) return str[now];

    int next = (now + a[idx] + 24) % 12;
    return go(next, idx + 1);
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s[7] = {0,2,4,5,7,9,11};
    vector<pair<char, char>> ans;
    for(int i = 0; i < 7; i++) {
        char ret = go(s[i], 0);
        if(ret != 'X') {
            ans.push_back({str[s[i]], ret});
        }
    }
    sort(ans.begin(), ans.end());
    for(auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}