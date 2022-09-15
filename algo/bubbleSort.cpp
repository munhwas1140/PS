#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void b1(int *a, int n) {
    int comp = 0, swap = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(++comp && a[j-1] > a[j]) {
                swap++;
                Swap(&a[j], &a[j-1]);
            }
        }
    }
    cout << comp << ' ' << swap << ' ';
}
void b2(int *a, int n) {
    int comp = 0, swap = 0;
    for(int i = 1; i < n; i++) {
        bool swapped = false;
        for(int j = 1; j <= n - i; j++) {
            if(++comp && a[j-1] > a[j]) {
                swap++;
                Swap(&a[j], &a[j-1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    cout << comp << ' ' << swap << ' ';
}
void b3(int *a, int n) {
    int comp = 0, swap = 0;
    int last = n;
    while(last) {
        int pos = 0;
        for(int i = 1; i < last; i++) {
            if(++comp && a[i-1] > a[i]) {
                swap++;
                Swap(&a[i], &a[i-1]);
                pos = i;
            }
        }
        last = pos;
    }
    cout << comp << ' ' << swap << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int a[1000], b[1000], c[1000];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            c[i] = b[i] = a[i];
        }
        b1(a, n); b2(b, n); b3(c, n);
    }     
      
    return 0;
}