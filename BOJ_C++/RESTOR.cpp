#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
            if(i + j < n1 && s1[i + j] == s2[j]) cnt++;
            else break;
        }
        ans = max(ans, cnt);
    }
    return ans;
}
int overlap(string& s1, string& s2)
{
	for (int len = min(s1.size(), s2.size()); len > 0; len--) {
		if (s1.substr(s1.size() - len) == s2.substr(0, len)) {
			return len;
		}
	}
	return 0;
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

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    while (true) {
        bool removed = false;
        for (int i = 1; i <= n && !removed; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && a[i].find(a[j]) != -1) {
                    a[j] = a[n];
                    n--;
                    removed = true;
                }
            }
        }
        if (!removed) break;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            b[i][j] = overlap(a[i], a[j]);
        }
    }

    memset(dp,-1,sizeof(dp));
    back(1, 0);
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