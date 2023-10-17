#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define DICT_LEN 3
#define MAX_TRIES 6

int main() {
    string dictionary[] = {"space", "wheel", "program"};
    srand(time(NULL));
    string prob = dictionary[rand()%DICT_LEN];
    int length = prob.length();
    int tries = 0;
    string ans(length, '-');
    cout << "current state : \"" << ans << "\"\n";

    while(tries < MAX_TRIES && ans != prob) {
        char c;
        cout << "guess a letter : ";
        cin >> c;
        if(ans.find(c) != string::npos) {
            cout << c << " is guessed previously.\n";
            continue;
        }
        int pos = prob.find(c);
        if(pos == string::npos) {
            cout << c << " is not in the target string.\n";
            tries += 1;
            continue;
        }
        do {
            ans[pos] = c;
            pos = prob.find(c, pos + 1);
        } while(pos != string::npos);
        cout << "current state : \"" << ans << "\"\n";
        if(ans == prob) {
            cout << "You WON!!\n";
            break;
        }
    }
    if(tries >= MAX_TRIES) {
        cout << "You lost : the answer was \"" << prob << "\"\n";
    }
}