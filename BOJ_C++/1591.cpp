#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
map<vector<int>, int> M;
vector<vector<int>> aa;
int indeg[1010];
int outdeg[1010];
int g[1010][1010];
int n, m;
int cnt;
vector<int> ans;
void go(int now) {
    for(int i = 0; i < cnt; i++) {
        while(g[now][i]) {
            g[now][i]--;
            go(i);
        }
    }
    ans.push_back(now);
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n - m + 1; i++) {
        vector<int> a, b;
        for(int j = 0; j < m; j++) {
            int tmp; cin >> tmp;
            if(j < m - 1) a.push_back(tmp);
            if(j > 0) b.push_back(tmp);
        }
        if(!M.count(a)) {
            M[a] = cnt++;
            aa.push_back(a);
        }
        if(!M.count(b)) {
            M[b] = cnt++;
            aa.push_back(b);
        }
        int t1 = M[a], t2 = M[b];
        outdeg[t1]++;
        indeg[t2]++;
        g[t1][t2]++;
    }
    int s, e;
    s = e = 0;
    for(int i = 0; i < cnt; i++) {
        if(indeg[i] - outdeg[i] == 1) {
            e = i;
        } else if(outdeg[i] - indeg[i] == 1) {
            s = i;
        }
    }
    go(s);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size() - 1; i++) {
        cout << aa[ans[i]][0] << ' ';
    }
    for(int &i : aa[ans[ans.size() - 1]]){
        cout << i << ' ';
    }
    return 0;
}