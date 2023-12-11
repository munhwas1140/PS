#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b;
int main() {
    fastio;
    cin >> a >> b;
    a += b;
    int n = a.size();
    vector<int> fail(n);
    vector<int> ans;
    for(int i = 1, j = 0; i < n; i++) {
        while(j > 0 && a[j] != a[i]) j = fail[j - 1];
        if(a[i] == a[j]) fail[i] = ++j;
    }
    ans.push_back(n);
    int x = n - 1;
    while(fail[x] > 0) {
        ans.push_back(fail[x]);
        x = fail[x - 1];
    }
    sort(ans.begin(), ans.end());
    
    for(int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}