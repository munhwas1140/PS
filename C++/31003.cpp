#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[3000];
int ind[3000];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(gcd(a[i], a[j]) != 1) {
                g[j].push_back(i);
                ind[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int now = -1;
        int idx = -1;
        for(int j = 0; j < n; j++) {
            if(ind[j] == 0) {
                if(now == -1 || now > a[j]) {
                    now = a[j];
                    idx = j;
                }
            }
        }

        for(int x : g[idx]) ind[x]--;
        ind[idx]--;
        cout << now << ' ';
    }
    cout << '\n';
    return 0;
}