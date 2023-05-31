#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> g[50], odd, even;
int n, a[50], con[50];
bool isPrime[2001], visited[50];
bool dfs(int now, int x1, int x2) {
    for(int &idx : g[now]) {
        int next = even[idx];
        if(next == x1 || next == x2) continue;
        if(visited[idx]) continue;
        visited[idx] = true;
        if(con[idx] == -1 || dfs(con[idx], x1, x2)) {
            con[idx] = now;
            return true;
        }
    }

    return false;
}

bool check(int x1, int x2) {
    int cnt = 0;
    memset(con,-1,sizeof(con));
    for(int i = 0; i < odd.size(); i++) {
        if(odd[i] == x1 || odd[i] == x2) continue;
        memset(visited,false,sizeof(visited));
        if(dfs(i, x1, x2)) cnt++;
    }

    if(cnt == (n / 2) - 1) return true;
    return false;
}

int main() {
    fastio;
    fill(isPrime, isPrime + 2001, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= 2000; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= 2000; j += i) isPrime[j] = false;
        }
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    for(int i = 0; i < odd.size(); i++) {
        for(int j = 0; j < even.size(); j++) {
            if(isPrime[odd[i] + even[j]]) {
                g[i].push_back(j);
            }
        }
    }

    vector<int> ans;
    for(int i = 1; i < n; i++) {
        if(isPrime[a[0] + a[i]]) {
            if(check(a[0], a[i])) ans.push_back(a[i]);
        }
    }

    sort(ans.begin(), ans.end());
    if(ans.size()) for(int x : ans) cout << x << ' ';
    else cout << -1 << '\n';

    return 0;
}