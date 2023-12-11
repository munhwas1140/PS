#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string tmp;
    cin >> tmp;
    
    string str = "";
    for(char &x : tmp) {
        str += "#";
        str += x;
    }
    str += "#";
    int r = -1;
    int c = -1;
    int n = str.size();
    for(int i = 0; i < n; i++) {
        if(i <= r) a[i] = min(a[2 * c - i], r - i);
        else a[i] = 0;
        while(i - a[i] - 1 >= 0 && i + a[i] + 1 < n && str[i-a[i]-1] == str[i + a[i] + 1]) {
            a[i] += 1;
        }

        if(r < i + a[i]) {
            r = i + a[i];
            c = i;
        }
    }

    int ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
    }
    cout << ans << '\n';
    return 0;
}