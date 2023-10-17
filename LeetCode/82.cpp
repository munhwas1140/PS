#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates freom Sorted List II


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0,head);
        ListNode *prev = dummy, *current = head;
        
        while(current) {
            ListNode *next = current->next;
            while(next && current->val == next->val) {
                ListNode *tmp = next->next;
                delete next;
                next = tmp;
            }
            
            if(current->next == next) {
                prev = current;
            } else {
                prev->next = next;
                delete current;
            }
            current = next;
        }
        return dummy->next;
    }
};