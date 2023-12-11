#include <bits/stdc++.h>
using namespace std;

int cnt[26];

bool dfs(int sum, int k, int ksum,int idx ) {
    if(sum == 0) return true;
    if(sum < 0) return false;

    for(int i = ksum + 1; i >= k + 1; i--) {
        if(dfs(sum - i, i, ksum + i, idx + 1)) {
            cnt[idx] = i;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(!dfs(n, 0, 0, 0)) return !(cout << -1 << '\n');

    string ans(n, '*');
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) ans[--cnt[i]] = char('A' + i);
    }

    int pos = ans.find('*');
    for(int i = 0; i < 26; i++) {
        while(cnt[i]--) {
            ans[pos] = char('A' + i);
            pos = ans.find('*');
        }
    }
    cout<< ans << '\n';

    return 0;
}