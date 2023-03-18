#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000;
int n;
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {  
    vector<vector<int>> ret(n, vector<int>(n, 0));
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ret[i][j] = a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    
    return ret;
}
vector<vector<int>> powpow(vector<vector<int>> &a, int b) {    
    vector<vector<int>> st(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        st[i][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; i++) {
            cout << st[i][j] << ' ';
        }
        cout << '\n';
    }
    while(b) {
        if(b % 2) {
            st = mul(st, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return st;
}
int main() {
    fastio;
    int b;
    cin >> n >> b;

    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> ans = powpow(a, b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}