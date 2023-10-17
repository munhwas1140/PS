#include <bits/stdc++.h>
using namespace std;

// 트리

vector<int> a[50];
int n, x, root;

int DFS(int now) {
    int ans = 0;
    bool flag = true;
    for(int next : a[now]) {
        if(next == x) continue;
        ans += DFS(next);
        flag = false;
    }
    if(flag) return 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        if(tmp == -1) root = i;
        else a[tmp].push_back(i);
    }
    cin >> x;

    if(x == root) cout << 0 << '\n';
    else cout << DFS(root) << '\n';

    return 0;
}