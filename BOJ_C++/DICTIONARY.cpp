#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int ind[26];
bool g[26][26];
void solve() {
    memset(ind, 0, sizeof(ind));
    memset(g, false, sizeof(g));
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    bool valid = true;
    for(int i = 0; i < n - 1; i++) {
        int j = i + 1;
        int lsz = a[i].size();
        int rsz = a[j].size();
        for(int idx = 0; idx < min(lsz, rsz); idx++) {
            int cl = a[i][idx] - 'a';
            int cr = a[j][idx] - 'a';
            if(cl != cr) {
                if(g[cr][cl]) valid = false;
                if(!g[cl][cr]) {
                    g[cl][cr] = true;
                    ind[cr]++;
                }
                break;
            }
        }
    }

    if(valid) {
        queue<int> q;
        for(int i = 0; i < 26; i++) {
            if(ind[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            cout << char(now + 'a');
            for(int i = 0; i < 26; i++) {
                if(i == now) continue;
                if(g[now][i]) {
                    ind[i]--;
                    if(ind[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        cout << '\n';
    } else {
        cout << "INVALID HYPOTHESIS" << '\n';
    }

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}