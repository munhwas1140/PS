#include <bits/stdc++.h>
using namespace std;
template <class T>
void print_container(const T& container, string s = "") {
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for(; it != container.end(); it++) {
        cout << *it << ' ' << ' ';
    }
    cout << '\n';
}
int main() {
    char a[] = {'a','b','c','d','e','x','y','z','w'};
    vector<char> v(&a[5], &a[9]);
    deque<char> dq(v.begin(), v.end());
    list<char> l1(3,'x');
    list<char> l2(&a[0], &a[4]);
    list<char> l3(dq.begin(), dq.end());
    print_container(v, "v = ");
    print_container(dq, "dq = ");
    print_container(l1, "l1 = ");
    print_container(l2, "l2 = ");
    print_container(l3, "l3 = ");
    l2.push_front('+');
    print_container(l2, "l2 = ");
    l2.push_back('-');
    print_container(l2, "l2 = ");
    l2.pop_front();
    print_container(l2, "l2 = ");
    l2.pop_back();
    print_container(l2, "l2 = ");

    return 0;
}