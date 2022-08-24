#include <bits/stdc++.h>
using namespace std;
int a[2000001];
int p[2000001];
int n;

void manacher() {
    int i;
    int r = 0, c = 0;
    for(i = 0; i < n; i++) {
        if(i <= r) p[i] = min(r - i, p[2 * c - i]);
        else p[i] = 0;
        while((i-p[i]-1 >= 0 && i+p[i]+1 < n ) && (a[i-p[i]-1] == a[i+p[i]+1])) p[i] += 1;
        if(r < i + p[i]) {
            r = i + p[i];
            c = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int i;    
    cin >> n;

    for(i = 0; i < n; i++) {
        a[i * 2] = 0;
        cin >> a[i * 2 + 1];
    }
    n = n * 2 + 1;
    a[n - 1] = 0;
    
    manacher();

    int q;
    cin >> q;
    for(i = 0; i < q; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        if(p[t1+t2+1] >= t2 - t1 + 1) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}