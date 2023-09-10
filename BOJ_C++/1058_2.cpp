#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int s, n, m;
    cin >> s >> n >> m;
    
    int cnt = 0;

    
    for(int i = 0; i < n + m; i++) {
        int tmp; cin >> tmp;
        if(tmp == 1) cnt++;
        else cnt--;
        
        if(s < cnt) s *= 2;
    }
    cout << s << '\n';

    return 0;
}