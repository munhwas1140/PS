#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int dp[100001];
vector<int> pos[100001];
int go(int now) {
    if(now > n) {
        return -1;
    }

    int &ret = dp[now];
    if(ret != -2) return ret;

    int tmp = -1;
    for(auto &x : pos[now]) {
        tmp = max(tmp, go(now + x));
    }   
    if(tmp == -1) {
        ret = -1;
    } else ret = 1;
    
    ret = -ret;
    return ret;
}

int main() {
    fastio;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                pos[i].push_back(j);
                if(j * j != i) {
                    pos[i].push_back(i / j);
                }
            }
        }
    }


    fill(dp, dp + n + 1, -2);
    if(go(1) == -1) {
        cout << "Kali" << '\n';
    } else {
        cout << "Ringo" << '\n';
    }

    return 0;
}