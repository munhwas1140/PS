#include <iostream>
#include <string>
using namespace std;
int main() {
    string A[5] = {"6","4","41","8","44"};
    int pos[100] = {0, };
    int idx = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            string t1 = A[i] + A[j];
            string t2 = A[j] + A[i];
            pos[idx++] = stoi(t1);
            if(t1 != t2) {
                pos[idx++] = stoi(t2);
            }
        }
    }
    
    
    for(int i = 1; i < idx; i++) {
        int j = i - 1;
        int key = pos[i];
        while(j >= 0 && key <= pos[j]) {
            pos[j + 1] = pos[j];
            j -= 1;
        }   
        pos[j + 1] = key;
    }
    cout << pos[idx - 1] << '\n';

    return 0;
}
