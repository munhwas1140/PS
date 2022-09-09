#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
const int MAX = 1e6;

int main() {
    fastio;
    vector<bool> check(MAX + 1, true);
    vector<int> prime;
    check[0] = check[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(check[i]) { 
            prime.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                check[j] = false;
            }
        }
    }

    int n; cin >> n;

    vector<vector<int>> state(n, vector<int>(prime.size(), 0));
    vector<int> cnt(prime.size());
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 0; prime[j] <= x; j++) {
            while(x % prime[j] == 0) {
                x /= prime[j];
                cnt[j]++;
                state[i][j]++;
            }
        }
    }
    
    int ans = 1;
    int anscnt = 0;
    for(int i = 0; i < cnt.size(); i++) {
        int tmp = cnt[i] / n;
        ans *= pow(prime[i], tmp);
        for(int j = 0; j < n; j++) {
            if(state[j][i] < tmp) {
                anscnt += tmp - state[j][i];
            }
        }
    }

    cout << ans << ' ' << anscnt << '\n';
    return 0;
}