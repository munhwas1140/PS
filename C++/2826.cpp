#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

vector<pair<int,int>> a;
const int mod = 1e9 + 7;
int c[26];
int n;
int go(int dep) {
    if(dep == n) return 1;

    int ret = 0;
    int s = a[dep].first;
    int e = a[dep].second;
    if(s >= 1e6) {
        s = c[s - 1000000];
    } 
    if(e >= 1e6) {
        e = c[e - 1000000];
    }

    for(int i = s; i <= e; i++) {
        c[dep] = i;
        ret += go(dep + 1);
        ret %= mod;
    }
    return ret ;
}
int main() {
    fastio;
    cin >> n;
      

    for(int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        int t1, t2;
        if('a' <= str1[0] && str1[0] <= 'z') {
            t1 = str1[0] - 'a' + 1e6;
        } else t1 = stoi(str1);

        if('a' <= str2[0] && str2[0] <= 'z') {
            t2 = str2[0] - 'a' + 1e6;
        } else t2 = stoi(str2);

        a.push_back({t1, t2});
    }
    cout << go(0) << '\n';
    return 0;
}