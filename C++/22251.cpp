#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, k, p, x;

int number[][7] = {{1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0},
                   {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1},
                   {0, 1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 1, 1},
                   {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0},
                   {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
int g[10][10];

int check(int t1, int t2) {
    if (g[t1][t2] != -1) {
        return g[t1][t2];
    }

    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        cnt += abs(number[t1][i] - number[t2][i]);
    }

    g[t1][t2] = g[t2][t1] = cnt;
    return cnt;
}

int go(string now, int index, int cnt) {
    if (index == k) {
        if (cnt && 1 <= stoi(now) && stoi(now) <= n) {
            return 1;
        }
        return 0;
    }

    int ret = 0;

    int now_num = now[index] - '0';

    for (int i = 0; i <= 9; i++) {
        string next_str = now;
        next_str[index] = char(i + '0');

        int next_cnt = cnt + check(now_num, i);
        if (next_cnt > p) continue;
        ret += go(next_str, index + 1, cnt + check(now_num, i));
    }
    return ret;
}

int main() {
    fastio;
    cin >> n >> k >> p >> x;

    string str = to_string(x);

    int padding = k - (int)str.size();
    str = string(padding, '0') + str;

    memset(g, -1, sizeof(g));
    cout << go(str, 0, 0) << '\n';

    return 0;
}