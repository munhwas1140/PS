#include <bits/stdc++.h>
using namespace std;

// Unique Morse Code Words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-"
                            ,".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> cnt;
        for(string str : words) {
            string tmp = "";
            for(char c : str) {
                tmp += morse[c - 'a'];
            }
            cnt.insert(tmp);
        }
        return cnt.size();
    }
};