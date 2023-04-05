#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a[2] = {0, 1};
    int c = 2;
    cout << a << '\n';
    cout << &a << '\n';
    cout << a + 1 << '\n';
    cout << typeid(c).name() << '\n';
    cout << typeid(a).name() << '\n';
    cout << typeid(&a).name() << '\n';
    cout << &a + 1 << '\n';

    cout << *(a + 1) << '\n';

    return 0;
}