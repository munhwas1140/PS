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
int ind[26];
bool check[26];
vector<int> g[26];
int main() {
    fastio;
    cin >> n;
    int cnt = 0;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(char &x : a[i]) {
            check[x-'a'] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            for(int j = 0; j < i; j++) {
                string &t1 = a[i];
                string &t2 = a[j];
                int k = 0;
                while(k < t1.size() && k < t2.size()) {
                    if(t1[k] != t2[k]) {
                        g[t2[k] - 'a'].push_back(t1[k] - 'a');
                        ind[t1[k] - 'a']++;
                        break;
                    }
                    k++;
                }
                if(k == t1.size() && t1.size() < t2.size()) return !(cout << '!' << '\n');
            }
        }
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < 26; i++) {
        if(check[i]) {
            cnt++;
            if(ind[i] == 0) q.push(i);
        }
    }

    bool ambi = false;

    while(!q.empty()) {
        if(q.size() > 1) ambi = true;
        int now = q.front();
        cnt--;
        ans.push_back(now);
        q.pop();
        for(int &next : g[now]) {
            ind[next]--;
            if(ind[next] == 0) {
                q.push(next);
            }
        }
    }
    if(cnt != 0) cout << "!" << '\n';
    else if(ambi) cout << "?" << '\n';
    else {
        for(int n : ans) cout << char(n + 'a');
        cout << '\n';
    }
    return 0;
}