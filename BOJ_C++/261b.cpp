#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    
    bool ok = true;
    
    int ans1 = 'W' + 'L';
    int ans2 = 'D' + 'D';

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i][j] + a[j][i] != ans1 && a[i][j] + a[j][i] != ans2) {
                ok = false;
                break;
            }
        }
    }    

    if(ok) cout << "correct" << '\n';
    else cout << "incorrect" << '\n';
    return 0;
}