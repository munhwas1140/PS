#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n;
map<string, int> ID;
vector<int> g[101];
vector<int> gp[101];
vector<int> gsp[101];
bool visited[101];
vector<int> order;
vector<string> itos;
int SCCcnt, IDcnt;
int SCC[101];
int SCCsz[101];
int SCCoutdeg[101];
void init() {
    ID.clear(); order.clear();
    itos.erase(itos.begin(), itos.end());
    itos.push_back(" ");
    for(int i = 0; i < 101; i++) {
        g[i].clear();
        gp[i].clear();
        gsp[i].clear();
    }
    SCCcnt = IDcnt = 0;
    memset(SCCoutdeg,false,sizeof(SCCoutdeg));
    memset(visited,false,sizeof(visited));
    memset(SCCsz,0,sizeof(SCCsz));
    memset(SCC,0,sizeof(SCC));
}
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    SCCsz[num]++;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}
int main() {
    fastio;
    while(1) {
        init();
        cin >> n;
        if(n == 0) break;
        cin.ignore();

        for(int i = 0; i < n; i++) {
            string str;
            getline(cin, str);

            vector<string> res = split(str, ' ');

            string e = res[0];
            if(ID.count(e) == 0) {
                ID[e] = ++IDcnt;
                itos.push_back(e);
            }

            for(int j = 1; j < res.size(); j++) {
                string s = res[j];
                if(ID.count(s) == 0) {
                    ID[s] = ++IDcnt;
                    itos.push_back(s);
                }
                g[ID[s]].push_back(ID[e]);
                gp[ID[e]].push_back(ID[s]);
            }

        }

        for(int i = 1; i <= IDcnt; i++) {
            if(!visited[i]) dfs(i);
        }
        
        memset(visited,false,sizeof(visited));
        reverse(order.begin(), order.end());

        for(int &i : order) {
            if(!SCC[i]) dfs_rev(i, ++SCCcnt);
        }
        

        for(int i = 1; i <= IDcnt; i++) {
            for(int &next : g[i]) {
                int t1 = SCC[i];
                int t2 = SCC[next];
                if(t1 != t2) {
                    gsp[t2].push_back(t1);
                }
            }
        }

        memset(visited,false,sizeof(visited));
        queue<int> q;
        for(int i = 1; i <= SCCcnt; i++) {
            if(SCCsz[i] > 1) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int &next : gsp[now]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        vector<string> ans;
        for(int i = 1; i <= IDcnt; i++) {
            if(visited[SCC[i]]) {
                ans.push_back(itos[i]);
            }
        }
        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end());
        for(string &t : ans) {
            cout << t << ' ';
        }
        cout << '\n';
    }
    return 0;
}