#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int indeg[26], outdeg[26];
int ad[26][26];
vector<string> g[26][26];
vector<int> ans;
void init() {
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    memset(ad,0,sizeof(ad));
    ans.clear();
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            g[i][j].clear();
        }
    }
}
bool check() {
    int one, mone;
    one = mone = 0;
    for(int i = 0; i < 26; i++) {
        int tmp = indeg[i] - outdeg[i];
        if(tmp == -1) mone++;
        if(tmp == 1) one++;
        if(tmp < -1 || tmp > 1) return false;
    }
    return (one == 1 && mone == 1) || (one == 0 && mone == 0);
}
void makeeuler(int now) {
    for(int i = 0; i < 26; i++) {
        while(ad[now][i]) {
            ad[now][i]--;
            makeeuler(i);
        }
    }
    ans.push_back(now);
}
void print() {
    reverse(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++) {
        int s = ans[i - 1];
        int e = ans[i];
        cout << g[s][e].back() << ' ';
        g[s][e].pop_back();
    }
    cout << '\n';
}
void solve() {
    init();
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int s = a[i].front() - 'a';
        int e = a[i].back() - 'a';
        ad[s][e]++;
        indeg[e]++;
        outdeg[s]++;
        g[s][e].push_back(a[i]);
    }

    if(!check()) {
        cout << "IMPOSSIBLE" << '\n';
        return ;
    }

    for(int i = 0; i < 26; i++) {
        if(outdeg[i] == indeg[i] + 1) {
            makeeuler(i);
            print();
            return ;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(outdeg[i]) {
            makeeuler(i);
            print();
            return ;
        }
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