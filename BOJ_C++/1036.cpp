#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int sum[52][36];
int n;

string add(string a, string b) {
    string tmp = "";
    int c = 0;
    int idx = 0;
    while(idx < a.size() && idx < b.size()) {
        int lv, rv;
        if('A' <= a[idx] && a[idx] <= 'Z') {
            lv = a[idx] - 'A' + 10;
        } else lv = a[idx] - '0';

        if('A' <= b[idx] && b[idx] <= 'Z') {
            rv = b[idx] - 'A' + 10;
        } else rv = b[idx] - '0';
        
        int ret = lv + rv + c;
        c = 0;
        if(ret > 35) {
            ret -= 36;
            c = 1;
        }
        if(ret < 10) {
            tmp.push_back(char(ret + '0'));
        } else {
            tmp.push_back(char(ret - 10 + 'A'));
        }
        idx++;
    }
    
    while(idx < a.size()) {
        int lv;
        if('A' <= a[idx] && a[idx] <= 'Z') {
            lv = a[idx] - 'A' + 10;
        } else lv = a[idx] - '0';
        
        int ret = lv + c;
        c = 0;
        if(ret > 35) {
            ret -= 36;
            c = 1;
        }
        if(ret < 10) {
            tmp.push_back(char(ret + '0'));
        } else {
            tmp.push_back(char(ret - 10 + 'A'));
        }
        idx++;
    }

    while(idx < b.size()) {
        int lv;
        if('A' <= b[idx] && b[idx] <= 'Z') {
            lv = b[idx] - 'A' + 10;
        } else lv = b[idx] - '0';
        
        int ret = lv + c;
        c = 0;
        if(ret > 35) {
            ret -= 36;
            c = 1;
        }
        if(ret < 10) {
            tmp.push_back(char(ret + '0'));
        } else {
            tmp.push_back(char(ret - 10 + 'A'));
        }
        idx++;
    }
    if(c) tmp += '1';
    return tmp;
}
bool cmp(const int &a, const int &b) { 
    for(int i = 51; i >= 0; i--) {
        if(sum[i][a] && !sum[i][b]) {
            return false;
        } else if (!sum[i][a] && sum[i][b]) {
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = a[i].size() - 1; j >= 0; j--) {
            int t;
            if('A' <= a[i][j] && a[i][j] <= 'Z') {
                t = a[i][j] - 'A' + 10;
            } else {
                t = a[i][j] - '0';
            }
            int k = a[i].size() - 1 - j;
            sum[k][t] += 1;
            if(sum[k][t] > 35) {
                sum[k][t] = 0;
                sum[k+1][t] += 1;
            }
        }
    }
    int k;
    cin >> k;
    vector<int> tmpv(36);
    for(int i = 0; i < 36; i++) tmpv[i] = i;
    sort(tmpv.begin(), tmpv.end(), cmp);
    vector<char> change;
    
    for(int i = 0; i < k; i++) {
        if(tmpv[35 - i] >= 10) {
            char c = char(tmpv[35 - i] - 10 + 'A');
            change.push_back(c);
        } else {
            change.push_back(char(tmpv[35-i] + '0'));
        }
    }

    sort(change.begin(), change.end());
    for(int i = 0; i < n; i++) {
        for(char &c : a[i]) {
            if(find(change.begin(), change.end(), c) != change.end()) {
                c = 'Z';
            }
        }
    }

    string ans = a[0];
    reverse(ans.begin(), ans.end());
    
    for(int i = 1; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
        ans = add(ans, a[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}