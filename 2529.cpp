#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int ind[2][10];
int ans[2][10];
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
            ind[0][i]++;
            ind[1][i]++;
        } else {
            g[i].push_back(i+1);
            ind[0][i+1]++;
            ind[1][i+1]++;
        }
    }
    priority_queue<int> q2;
    priority_queue<int, vector<int>, greater<int>> q1;
    for(int i = 0; i < n + 1; i++) {
        sort(g[i].begin(), g[i].end());
        if(ind[0][i] == 0) {
            q1.push(i);
            q2.push(i);
        }
    }

    int s = 9;
    while(!q1.empty()) {
        int now = q1.top();
        q1.pop();
        ans[0][now] = s--;
        for(int &next : g[now]) {
            ind[0][next]--;
            if(ind[0][next] == 0) {
                q1.push(next);
            }
        }
    }
    
    s = n;
    while(!q2.empty()) {
        int now = q2.top();
        q2.pop();
        ans[1][now] = s--;
        for(int i = g[now].size() - 1; i >= 0; i--) {
            int next = g[now][i];
            ind[1][next]--;
            if(ind[1][next] == 0) {
                q2.push(next);
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n + 1; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}