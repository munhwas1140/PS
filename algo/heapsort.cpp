#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int Heap[2020], sz, cnt;

void heapInsert(int v) {
    Heap[++sz] = v;
    int idx = sz;
    while(idx != 1 && v > Heap[idx / 2]) {
        int tmp = Heap[idx];
        Heap[idx] = Heap[idx / 2];
        Heap[idx / 2] = tmp;
        idx /= 2;
    }
}

void makeHeap(int *a, int n) {
    for(int i = 1; i <= n; i++) {
        heapInsert(a[i]);
    }
}

int heapTop() {
    int ret = Heap[1];
    Heap[1] = Heap[sz];
    Heap[sz] = -1e9;
    sz--;

    int p = 1;
    while(true) {
        int child = p * 2;
        if(child + 1 <= sz) {
            cnt += 2;
            if(Heap[child + 1] > Heap[child]) {
                child++;
            }
            if(Heap[child] < Heap[p]) break;
        } else if(child <= sz) {
            cnt++;
            if(Heap[child] < Heap[p]) break;
        } else {
            break;
        }
        
        
        int tmp = Heap[child];
        Heap[child] = Heap[p];
        Heap[p] = tmp;
        p = child;
    }
    return ret;
}

void heapSort(int *a, int n) {
    makeHeap(a, n);
    for(int i = n; i >= 1; i--) {
        a[i] = heapTop();
    }
    return ;
}

void init() {
    for(int i = 0; i < 2020; i++) {
        Heap[i] = -1e9;
    }
    sz = 0;
    cnt = 0;
}

void solve() {
    init();
    int n, a[1001] = {0, };

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    heapSort(a, n);

    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    cout << cnt << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}