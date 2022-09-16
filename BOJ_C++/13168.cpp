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
ll r, dist[2][100][100];
int main() {
    fastio;
    cin >> n >> r;
    map<string, int> M;
    string str;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[0][i][j] = dist[1][i][j] = (i == j ? 0 : 1e9);
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(M.find(str) == M.end()) {
            M[str] = cnt++;
        }
    }     
    
    int s; cin >> s;
    vector<int> seq;
    for(int i = 0; i < s; i++) {
        string str; cin >> str;
        seq.push_back(M[str]);
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        string s1, s2, s3;
        ll cost;
        cin >> s1 >> s2 >> s3 >> cost;
        int s = M[s2];
        int e = M[s3];
        cost *= 2;
        dist[0][s][e] = min(dist[0][s][e], cost);
        dist[0][e][s] = min(dist[0][e][s], cost);
        if(s1 == "S-Train" || s1 == "V-Train") cost /= 2;
        else if(s1 == "Mugunghwa" || s1 == "ITX-Saemaeul" || s1 == "ITX-Cheongchun") cost = 0;
        dist[1][s][e] = min(dist[1][s][e], cost);
        dist[1][e][s] = min(dist[1][e][s], cost);
    }

    
    for(int k = 0; k < cnt; k++) {
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j < cnt; j++) {
                for(int z = 0; z < 2; z++) {
                    dist[z][i][j] = min(dist[z][i][j], dist[z][i][k] + dist[z][k][j]);
                }
            }
        }
    }

    ll t1, t2;
    t1 = t2 = 0;
    for(int i = 0; i < s - 1; i++) {
        t1 += dist[0][seq[i]][seq[i+1]];
        t2 += dist[1][seq[i]][seq[i+1]];
    }
    t2 += r * 2;
    if(t1 <= t2) cout << "No" << '\n';
    else cout << "Yes" << '\n';
      
    return 0;
}