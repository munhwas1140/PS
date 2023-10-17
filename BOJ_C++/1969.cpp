#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int f(char c) {
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    return 0;
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> cnt(m, vector<int>(4, 0));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            cnt[j][f(a[i][j])]++;
        }
    }

    int num = 0;
    
    for(int i = 0; i < m; i++) {
        int idx = 0;
        for(int j = 0; j < 4; j++) {
            if(cnt[i][idx] < cnt[i][j]) {
                idx = j;
            }
        }
        num += n - cnt[i][idx];
        if(idx == 0) cout << 'A';
        else if(idx == 1) cout << 'C';
        else if(idx == 2) cout << 'G';
        else cout << 'T';
    }
    cout << '\n';
    cout << num << '\n';

    return 0;
}