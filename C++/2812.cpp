#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    string str;
    cin >> n >> k >> str;

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        while(!ans.empty() && ans.back() < str[i] && k) {
            ans.pop_back();
            k--;
        }
        ans.push_back(str[i]);
    }
    while(k) {
        ans.pop_back();
        k--;
    }
    for(int &x : ans) {
        cout << x - '0';
    }

    return 0;
}