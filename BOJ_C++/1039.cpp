#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

bool check[1000001][2];
int main() {
    fastio;
    memset(check,false,sizeof(check));
    string str; int k;
    cin >> str >> k;

    int ans = -1;
    int sz = str.size();
    if(sz == 1 || (sz == 2 && str[1] == '0')) return !(cout << -1 << '\n');
    check[stoi(str)][0] = true;
    queue<pair<string, int>> q;
    q.push({str, 0});

    while(!q.empty()) {
        auto [now, cnt] = q.front();
        q.pop();
        
        if(cnt % 2 == k % 2) {
            ans = max(ans, stoi(now));
            if(cnt == k) continue;
        }

        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                if(i == 0 && now[j] == '0') continue;
                swap(now[i], now[j]);
                int next = stoi(now);
                if(!check[next][(cnt + 1) % 2]) {
                    check[next][(cnt + 1) % 2] = true;
                    q.push({now, cnt + 1});
                }
                swap(now[i], now[j]);
            }
        } 
    }     
      
    cout << ans << '\n';
    return 0;
}