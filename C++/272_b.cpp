#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    bool check[101][101] = {false};
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> a(k);
        for(int j = 0; j < k; j++) {
            cin >> a[j];
        }

        for(int j = 0; j < k; j++) {
            for(int l = j + 1; l < k; l++) {
                check[a[j]][a[l]] = true;
                check[a[l]][a[j]] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(check[i][j] == false) return !(cout << "No" << '\n');
        }
    }
    cout << "Yes" << '\n';
    return 0;
}