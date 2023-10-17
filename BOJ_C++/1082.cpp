#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;

    vector<int> price(n);
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    int m; cin >> m;

    int a = -1;
    int tmp = 1e9;
    for(int i = 1; i < n; i++) {
        if(tmp > price[i]) {
            a = i;
            tmp = price[i];
        }
    } 
    int b = a;
    if(tmp > price[0]) b = 0;

    if(a == -1 || price[a] > m) cout << 0 << '\n';
    else {
        vector<int> ans;
        ans.push_back(a);
        m -= price[a];
        while(m >= price[b]) {
            m -= price[b];
            ans.push_back(b);
        }

        sort(ans.begin(), ans.end(), greater<int>());
        
        for(int i = 0; i < ans.size(); i++) {
            for(int j = n - 1; j > ans[i]; j--) {
                if(price[ans[i]] + m >= price[j]) {
                    m -= price[j] - price[ans[i]];
                    ans[i] = j;
                    break;
                }
            }
        }

        for(int &x : ans) {
            cout << x;
        }
        cout << '\n';
    }

    return 0;
}