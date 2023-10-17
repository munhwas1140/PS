#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<pair<int,int>> g[101];
int jewel[101];
bool visited[101][1 << 14];
int n, m, k;

int main() {
    fastio;
    memset(jewel,-1,sizeof(jewel));
    cin >> n >> m >> k;
    for(int i = 0, tmp; i < k; i++) {
        cin >> tmp;
        jewel[tmp] = i;
    }

    while(m--) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }
    
    int ans = 0;
    
    queue<tuple<int,int,int>> q;
    q.push({1,0,0});
    visited[1][0] = true; 
    while(!q.empty()) {
        auto [now, cnt, state] = q.front();
        q.pop();

        if(now == 1) {
            ans = max(ans, cnt);
        }
        for(auto p : g[now]) {
            int next = p.first;
            int maximum = p.second;
            if(maximum < cnt) continue;
            if(visited[next][state] == false) {
                visited[next][state] = true;
                q.push({next, cnt, state});
            }

            int je = jewel[next];
            if(je != -1) {
                int tmp = cnt;
                if((state & (1 << je)) == 0) tmp += 1;
                if(visited[next][state|(1<<je)] == false) {
                    visited[next][state|(1<<je)] = true;
                    q.push({next,tmp,state|(1<<je)});
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}