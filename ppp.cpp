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
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> seq;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0) {
                if(a[i] < a[i-1]) {
                    for(int j = 0; j < i - 1; j++) {
                        if(a[i-j] > a[i-j-1]) break;
                        seq.push_back({i-j, i-j+1});
                        if((a[i-j] + a[i-j-1]) % 2 == 1) {
                            a[i-j] = a[i-j-1];
                            break;
                        }
                        a[i-j] = a[i-j-1];
                    }
                }
            }
        }
        cout << seq.size() << '\n';
        for(auto &p : seq) {
            cout << p.first << ' ' << p.second << '\n';
        }

    }

    return 0;
}