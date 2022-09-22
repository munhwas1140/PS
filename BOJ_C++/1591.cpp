#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n, m;
vector<vector<int>> a;
map<vector<int>, int> M;
int indeg[1000];
int outdeg[1000];
vector<int> g[1000];
vector<int> ans;

void go(int now) {
    for(int &next : g[now]) {
        if(indeg[next]) {
            outdeg[now]--;
            indeg[next]--;
            go(next);
        }
    }
    ans.push_back(a[now][0]);
}

int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n - m + 1; i++) {
        vector<int> tmp(m);
        for(int j = 0; j < m; j++) {
            cin >> tmp[j];
        }
        if(M.find(tmp) != M.end()) {
            int idx = M[tmp];
            g[idx].push_back(idx);
            indeg[idx]++;
            outdeg[idx]++;
        } else {
            M[tmp] = (int)a.size();
            a.push_back(tmp);
        }
    }

    if(n == m) {
        for(int i = 0; i < m; i++) {
            cout << a[0][i] << ' ';
        }
        return 0;
    }
    int sz = a.size(); 
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            if(i == j) continue;
            bool ok = true;
            for(int k = 0; k < m - 1; k++) {
                if(a[i][k+1] != a[j][k]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                g[i].push_back(j);
                outdeg[i]++;
                indeg[j]++;
            }
        }
    }
    
    int s = 0, e = 0;
    for(int i = 0; i < sz; i++) {
        // cout << indeg[i] << ' ' << outdeg[i] << '\n';
        if(indeg[i] - outdeg[i] == 1) {
            e = i;
        } else if(outdeg[i] - indeg[i] == 1) {
            s = i;
        }
    }

    go(s);
    reverse(ans.begin(), ans.end());

    for(int &i : ans) {
        cout << i << ' ';
    }
    for(int i = 1; i < m; i++) {
        cout << a[e][i] << ' ';
    }
    cout << '\n';
    return 0;
}