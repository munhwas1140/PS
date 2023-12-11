#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n;
vector<int> g[101];
int dist[101];
void go(int now, int stat) {
    for(int next : g[now]) {
        if(dist[next] == -1) {
            dist[next] = stat ^ 1;
            go(next, stat ^ 1);
        }
    }
}
int main() {
    fastio;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int tmp; cin >> tmp;
            g[i].push_back(tmp);
        }
    }   

    memset(dist,-1,sizeof(dist));
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] == -1) {
            dist[i] = 0;
            go(i, 0);
        }
    }
    vector<int> v0, v1;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == 0) v0.push_back(i);
        else v1.push_back(i);
    }

    cout << v0.size() << '\n';
    for(int x : v0) cout << x << ' ';
    cout << '\n';

    cout << v1.size() << '\n';
    for(int x : v1) cout << x << ' ';
    cout << '\n';
    return 0;
}