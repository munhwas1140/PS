#include <iostream>
using namespace std;

void hanoi_tower(int n, int a, int b, int c, unsigned long long k, int *count) {
    if (n > 0) {
        hanoi_tower(n - 1, a, c, b, k, count);
        (*count)++;
        if (*count == k) {
            cout << a << " " << c << endl;
            return;
        }
        hanoi_tower(n - 1, b, a, c, k, count);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        unsigned long long b;
        cin >> a >> b;
        int count = 0;
        unsigned long long standard = 1ULL << (a - 1);
        int even_odd = 0;
        for (int i = 0; i < a; i++) {
            if (b > standard) {
                b = b - standard;
                standard = standard >> 1;
                even_odd++;
            } else {
                break;
            }
        }
        if (even_odd % 2 == 0) {
            hanoi_tower(a - even_odd, 1, 2, 3, b, &count);
        } else {
            hanoi_tower(a - even_odd, 2, 1, 3, b, &count);
        }
    }
    return 0;
}