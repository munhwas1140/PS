#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int ind[10];
vector<int> g[10];
int main() {
    fastio;
    int n; cin >> n;
    vector<char> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == '<') {
            g[i+1].push_back(i);
            ind[i]++;
        } else {
            g[i].push_back(i+1);
            ind[i+1]++;
        }
    }

    for(int i = 0; i < n; i++) {
        
    }

    return 0;
}