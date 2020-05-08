//
// Created by Administrator on 2020/5/7 0007.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        bool carry = false;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            ListNode* node = new ListNode(val%10);
            p->next = node;
            p = p->next;
            carry = (val >= 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int val = l1->val + carry;
            ListNode* node = new ListNode(val%10);
            p->next = node;
            p = p->next;
            carry = (val >= 10);
            l1 = l1->next;

        }
        while(l2){
            int val = l2->val + carry;
            ListNode* node = new ListNode(val%10);
            p->next = node;
            p = p->next;
            carry = (val >= 10);
            l2 = l2->next;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            p->next = node;
        }
        return dummyHead->next;
    }
};