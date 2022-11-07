#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p1[1001], p2[1001];
int Find1(int x) {
    if(p1[x] < 0) return x;
    return p1[x] = Find1(p1[x]);
}
int Find2(int x) {
    if(p2[x] < 0) return x;
    return p2[x] = Find2(p2[x]);
}

void set_union1(int x, int y) {
    x = Find1(x);
    y = Find1(y);

    if(x == y) return;
    p1[x] = y;
}
void set_union2(int x, int y) {
    x = Find2(x);
    y = Find2(y);
    if(x == y) return ;
    p2[x] = y;
}
int main() {
    fastio;
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    memset(p1,-1,sizeof(p1));
    memset(p2,-1,sizeof(p2));

    for(int i = 0; i < m1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union1(t1, t2);
    }

    for(int i = 0; i < m2; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        set_union2(t1, t2);
    }

    vector<pii> ans;
    while(true) {
        bool check = false;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int x1, y1, x2, y2;
                x1 = Find1(i);
                y1 = Find1(j);

                x2 = Find2(i);
                y2 = Find2(j);
                
                if(x1 != y1 && x2 != y2) {
                    set_union1(x1, y1);
                    set_union2(x2, y2);
                    ans.push_back({i, j});
                    check = true;
                }
            }
        }
        if(!check) break;
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}