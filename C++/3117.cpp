#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, k, m;
int p[100001][31];
int main() {
    fastio;
    cin >> n >> k >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    for(int i = 1; i <= k; i++) {
        cin >> p[i][0];
    }
    m -= 1;
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= k; j++) {
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    for(int i = 0; i < n; i++) {
        int tmp = a[i];
        for(int j = 30; j >= 0; j--) {
            if(m & (1 << j)) tmp = p[tmp][j];
        }
        cout << tmp << ' ';
    } 
      
    return 0;
}