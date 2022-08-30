// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;

// int n;
// vector<string> a;
// bool check[10];
// int num[255];
// int cnt = 0;
// int ans = -1;

// void go(int idx, int ct) {
//     // cout << idx << ' ' << ct << '\n';
//     if(ct == cnt) {
//         int tmp = 0;
//         for(auto &s : a) {
//             int now = 0;
//             for(int i = 0; i < s.size(); i++) {
//                 now = now * 10 + num[s[i]];
//             }
//             tmp += now;
//             // cout << now << '\n';
//         }

//         ans = max(ans, tmp);
//         return ;
//     }

//     for(; num[idx] == -1; idx++);
//     for(int i = 9; i > 9 - cnt; i--) {
//         if(check[i]) continue;
//         num[idx] = i;
//         check[i] = true;
//         go(idx + 1, ct + 1);
//         num[idx] = 0;
//         check[i] = false;
//     }
//     return ;
// }

// int main() {
//     fastio;
//     cin >> n;
//     a.resize(n);
//     memset(num, -1, sizeof(num));
//     int tmp = 9;
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//         for(char &c : a[i]) {
//             if(num[c] == -1) {
//                 num[c] = 0;
//                 cnt += 1;
//             }
//         }
//     }


//     go(0,0);

//     cout << ans << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n; cin >> n;
    int a[26] = {0};
    for(int i = 0; i < n; i++) {
        int w = 1; string str;
        cin >> str;
        for(int j = str.size() - 1; j >= 0; j--) {
            a[str[j] - 'A'] += w;
            w *= 10;
        } 
    }    
    sort(a, a + 26);
    int ans = 0;
    for(int i = 9; i >= 0; i--) {
        ans += a[i+16] * i;
    }
    cout << ans << '\n';
      
    return 0;
}