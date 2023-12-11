#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
const int MAX = 1e6;
int cnt[101][100000];
int main() {
    fastio;
    vector<int> prime;
    vector<bool> check(MAX + 1);
    check[0] = check[1] = true;
    for(int i = 2; i <= MAX; i++) {
        if(!check[i]) {
            check[i] = false; prime.push_back(i);
            for(int j = i + i; j <= MAX; j += i) check[j] = true;
        }
    }
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; tmp >= prime[j] ;j++) {
            while(tmp % prime[j] == 0) {
                cnt[n][j]++;
                cnt[i][j]++;
                tmp /= prime[j];
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < prime.size(); i++) {
        cnt[n][i] /= n;
        ans *= (int)pow(prime[i], cnt[n][i]);
    }
    int anscnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < prime.size(); j++) {
            if(cnt[i][j] < cnt[n][j]) {
                anscnt += cnt[n][j] - cnt[i][j];
            }
        }
    }

    cout << ans << ' ' << anscnt << '\n';
    return 0;
}