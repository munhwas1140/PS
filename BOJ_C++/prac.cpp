#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a,int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> lv(n1+1);
    vector<int> rv(n2+1);
    for(int i = 0; i < n1; i++) {
        lv[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++) {
        rv[i] = a[m + 1 + i];
    }

    lv[n1] = 1e9;
    rv[n2] = 1e9;

    int i = 0;
    int j = 0;
    for(int k = l; k <= r; k++) {
        if(lv[i] < rv[j]) {
            a[k] = lv[i];
            i += 1;
        } else {
            a[k] = rv[j];
            j += 1;
        }
    }
    return ;
}

void merge_sort(vector<int> &a, int l, int r) {
    if(l < r) {
        int m = (l + r) >> 1;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main() {
    vector<int> a = {3,4,1,15,6,4,2,3,4,6};
    merge_sort(a,0,a.size() - 1);
    for(int x : a) {
        cout << x << ' ';
    }
    return 0;
}