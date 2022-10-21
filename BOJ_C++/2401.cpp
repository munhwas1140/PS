#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string str;
bool a[100001][500];
int dp[100001];
int nsz[500];
int n;
int go(int now) {
    if(now == str.size()) return 0;

    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = go(now + 1);
    
    for(int i = 0; i < n; i++) {
        if(a[now][i]) {
            ret = max(ret, go(now + nsz[i]) + nsz[i]);
        }
    }

    return ret;
}

vector<int> getPi(string &p) {
    int m = (int)p.size();
    int j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(string &s, string &p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size() , m = (int)p.size(), j = 0;
    for(int i = 0; i < n; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if(s[i] == p[j]) {
            if(j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}
int main() {
    fastio;
    cin >> str;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        nsz[i] = tmp.size();
        vector<int> t = kmp(str, tmp); 
        for(int x : t) {
            a[x][i] = true;
        }
    }

    memset(dp,-1,sizeof(dp)); 
    cout << go(0) << '\n';

    return 0;
}