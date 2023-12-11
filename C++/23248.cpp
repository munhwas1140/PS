#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> a[100001];
vector<int> b[100001];
int xlast[100001];
int ylast[100001];
int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
    }

    for(int i = 1; i < n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    for(int i = 1; i < m; i++) {
        sort(b[i].begin(), b[i].end());
    }

    for(int i = 1; i < 100001; i++) {
        xlast[i] = 100000;
        ylast[i] = 100000;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(xlast[i] > a[i].front()) {
            ans++;
        }
    }
    

    return 0;
}

