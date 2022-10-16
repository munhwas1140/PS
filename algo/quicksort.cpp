#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int swapHoare, compHoare;
int swapLomuto, compLomuto;
int partition_Hoare(vector<int> &a, int lo, int hi) {
    int pivot = a[lo];
    int i = lo - 1;
    int j = hi + 1;
    while(true) {
        do {
            i++;
        } while(++compHoare && a[i] < pivot);
        do {
            j--;
        } while(++compHoare && a[j] > pivot);
        if(i < j) {
            swapHoare++;
            swap(a[i], a[j]);
        } else return j;
    }
}
void Hoare(vector<int> &a, int lo, int hi) {
    if(lo >= hi) return;

    int p = partition_Hoare(a, lo, hi);
    Hoare(a, lo, p);
    Hoare(a, p + 1, hi);
    return ;
}

int partition_Lomuto(vector<int> &a, int lo, int hi) {
    int pivot = a[lo];
    int j = lo;
    for(int i = lo + 1; i <= hi; i++) {
        if(++compLomuto && a[i] < pivot) {
            j++;
            swap(a[i],a[j]);
            swapLomuto++;
        }
    }
    int pivot_pos = j;
    swapLomuto++;
    swap(a[pivot_pos], a[lo]);
    return pivot_pos;

}
void Lomuto(vector<int> &a, int lo, int hi) {
    if(lo >= hi) return ;
    
    int p = partition_Lomuto(a, lo, hi);
    Lomuto(a, lo, p - 1);
    Lomuto(a, p + 1, hi);
    return ;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    compHoare = compLomuto = swapLomuto = swapHoare = 0;
    Hoare(a, 0, n - 1);
    Lomuto(b, 0, n - 1);
    cout << swapHoare << ' ' << swapLomuto << ' ' << compHoare << ' ' << compLomuto << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}