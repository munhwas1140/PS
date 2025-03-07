#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> g[1000];
vector<int> g_tree[1000];
int indeg[1000];

int main() {
    fastio;
    int n;
    cin >> n;

    vector<string> a(n);
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string t1, t2;
        cin >> t1 >> t2;

        int x1 = mp[t1];
        int x2 = mp[t2];

        g[x2].push_back(x1);
        indeg[x1] += 1;
    }

    vector<string> roots;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            roots.push_back(a[i]);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : g[now]) {
            indeg[next] -= 1;
            if (indeg[next] == 0) {
                q.push(next);
                g_tree[now].push_back(next);
            }
        }
    }

    sort(roots.begin(), roots.end());
    cout << roots.size() << '\n';
    for (string root : roots) {
        cout << root << ' ';
    }
    cout << '\n';

    for (auto node : mp) {
        cout << node.first << ' ' << g_tree[node.second].size() << ' ';

        vector<string> tmp;
        for (int child : g_tree[node.second]) {
            tmp.push_back(a[child]);
        }
        sort(tmp.begin(), tmp.end());
        for (string x : tmp) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}