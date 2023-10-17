#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
bool visited[10];
char per[10];
bool check(int n) {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (per[i] - 'a') * (i % 2 ? -1 : 1);
    }
    return ret > 0;
}
int go(char *str, int idx, int n) {
    if(idx == n) {
        return check(n);
    }
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            per[idx] = str[i];
            ret += go(str, idx + 1, n);
            visited[i] = false;
        }
    }
    return ret;
}
int len(char *str) {
    for(int i = 0; i < 10; i++) {
        if(!str[i]) return i;
    }
    return -1;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        char str[10] = {0};
        cin >> str;
        cout << go(str, 0, len(str)) << '\n';
    }

    return 0;
}