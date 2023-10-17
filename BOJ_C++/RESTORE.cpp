#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool noUse[16];
string a[16];
int n;
int b[16][16]; // i -> j 겟수
int dp[1 << 16][16];

int check(int u, int v) {
    string s1 = a[u], s2 = a[v];
    int n1 = s1.size(), n2 = s2.size();
    int ans = -1;
    for(int i = n1 - 1; i >= 0; i--) {
        int cnt = 0;
        for(int j = 0; j < n2; j++) {
            if(i + j >= n1) break;

            if(s1[i + j] == s2[j]) cnt++;
            else {
                cnt = 0;
                break;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int go(int state, int last) {
    if(state == (1 << (n + 1)) - 1) {
        return 0;
    }

    int &ret = dp[state][last];
    if(ret != -1) return ret;
    ret = 1e9;

    for(int i = 1; i <= n; i++) {
        if((state & (1 << i)) == 0) {
            ret = min(ret, go(state | (1 << i), i) + (int)a[i].size() - b[last][i]);
        }
    }
    return ret;
}
void back(int state, int last) {
    if(state == (1 << (n + 1)) - 1) return ;
    
    for(int i = 1; i <= n; i++) {
        if((state & (1 << i)) == 0) {
            int t1 = go(state | (1 << i), i) + (int)a[i].size() - b[last][i];
            int t2 = go(state, last);
            if(t1 == t2) {
                for(int j = b[last][i]; j < a[i].size(); j++) {
                    cout << a[i][j];
                }
                back(state | (1 << i), i);
                return;
            }
        }
    }
}

void solve() {
    memset(b,0,sizeof(b));
    memset(noUse,false,sizeof(noUse));

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(a[i] == a[j]) {
                noUse[min(i, j)] = true;
                continue;
            }

            int tmp = check(i, j);
            if(tmp == a[j].size()) {
                noUse[j] = true;
            } else {
                b[i][j] = tmp;
            }
        }
    }

    int start = 1;
    for(int i = 1; i <= n; i++) {
        if(noUse[i]) start |= (1 << i);
    }

    memset(dp,-1,sizeof(dp));
    back(start, 0);
    cout << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}