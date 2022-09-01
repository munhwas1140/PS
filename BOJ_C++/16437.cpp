#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
ll w[123457];
vector<int> g[123457];
bool visited[123457];

ll go(int now) {
    visited[now] = true;
    ll ret = 0;
    for(int &next : g[now]) {
        if(!visited[next]) {
            ret += go(next);
        }
    }
    return (ret + w[now] < 0 ? 0 : ret + w[now]); 
}

int main() {
    fastio;
    cin >> n;
      
    for(int i = 2; i <= n; i++) {
        char c; ll t1; int t2;
        cin >> c >> t1 >> t2;
        if(c == 'W') {
            w[i] = -t1;
        } else {
            w[i] = t1;
        }
        g[t2].push_back(i);
    }

    cout << go(1) << '\n';
    return 0;
}