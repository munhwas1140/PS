#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == now + 1) {
            now++;
        } else {
            if((n - i) >= 2) {
                n -= 2;
                now++;
                i -= 1;
            } else break;
        }
    }
    cout << now << '\n';
    return 0;
}