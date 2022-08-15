#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> ans[i].first;
        ans[i].second = i + 1;
    }
    sort(ans.begin(), ans.end());
    while(m--) {
        int st, ed, k;
        cin >> st >> ed >> k;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i].second >= st && ans[i].second <= ed) cnt += 1;
            if(k == cnt) {
                cout << ans[i].first << '\n';
                break;
            }
        }
    }
}