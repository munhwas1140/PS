#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> seq(n);
        int cnt[10] = {0};
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            q.push({t,i});
            cnt[t] += 1;
        }
        int num = 1;
        while(!q.empty()) {
            const auto &[cost, idx] = q.front();
            q.pop();
            
            bool ok = true;
            for(int i = cost + 1; i <= 9; i++) {
                if(cnt[i] > 0) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                seq[idx] = num++;
                cnt[cost] -= 1;
            } else {
                q.push({cost, idx});
            }
        }
        cout << seq[m] << '\n';
    }     
      
    return 0;
}