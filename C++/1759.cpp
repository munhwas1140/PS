#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n, m;
char a[15];
string ans = "";
vector<bool> check(26, false);
void go(int idx, int sz, int mo, int ja) {
    if(idx == n) {
        if(sz == m && mo >= 1 && ja >= 2) cout << ans << '\n';
        return ;
    }

    ans += a[idx];
    if(check[a[idx] - 'a']) go(idx + 1, sz + 1, mo + 1, ja);
    else go(idx + 1, sz + 1, mo, ja + 1);
    ans.pop_back(); 

    go(idx + 1, sz, mo, ja);
}
    
int main() {
    fastio;
    cin >> m >> n;  
    for(int i = 0; i < n; i++) cin >> a[i];
    check[0] = check[4] = check[8] = check[14] = check[20] = true;
    sort(a, a + n);
    go(0,0,0,0);
    return 0;
}