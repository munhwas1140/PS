#include <bits/stdc++.h>
using namespace std;
int my_strlen(const char *str) {
    int i;
    for(i = 0; *str != '\0'; i++, str++);
    return i;
}

void my_strcpy(char *d, const char *s) {
    for(; *s; s ++) {
        *d++ = *s;
    }
    *d = '\0';
}

void my_strcat(char *d, const char *s) {
    while(*d) d++;
    for(; *s; s++) {
        *d++ = *s;
    }
    return ;
}

int main() {
    char s1[10], s2[10] = "xxx";
    my_strcpy(s1, "12");
    cout << "length of " << s1 << " is ";
    cout << my_strlen(s1) << '\n';
    
    my_strcpy(s2, s1);
    my_strcat(s2, "ab");
    cout << "length of " << s2 << " is ";
    cout << my_strlen(s2) << '\n';
    return 0;
}