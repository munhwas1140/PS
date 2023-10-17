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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<bool> check(n + 1);
    int mv = -1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(mv < a[i]) mv = a[i];
    }
    
    for(int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        check[tmp] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == mv && check[i]) {
            return !(cout << "Yes" << '\n');
        }
    }
    cout << "No" << '\n';

    return 0;
}