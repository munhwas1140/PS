#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, s, e;
vector<int> g[200001];
vector<int> ans;
bool visited[200001];
bool dfs(int now) {
    if(now == e) {
        ans.push_back(e);
        return true;
    }
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next] && dfs(next)) {
            ans.push_back(now);
            return true;
        }
    }
    visited[now] = false;
    return false;
}
int main() {
    fastio;
    cin >> n >> s >> e;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    dfs(s);
    reverse(ans.begin(), ans.end());
    for(int &i : ans) {
        cout << i << ' ';
    }
    return 0;
}