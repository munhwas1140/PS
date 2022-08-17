#include <bits/stdc++.h>
using namespace std;

// Merge Two Sorted Lists

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *ans = new ListNode();
        ListNode **head = &(ans->next);
        while(list1 && list2) {
            int lv = list1->val;
            int rv = list2->val;
            if(lv < rv) {
                ans->next = list1;
                list1 = list1->next;
            } else {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if(list1) ans->next = list1;
        if(list2) ans->next = list2;
        return *head;
    }
};