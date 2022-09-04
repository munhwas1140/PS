#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n + m; i++) {
        int tmp;
        cin >> tmp;
        auto it = s.find(tmp);
        if(it == s.end()) {
            s.insert(tmp);
        } else s.erase(it);
    }
    cout << s.size() << '\n';
      
    return 0;
}