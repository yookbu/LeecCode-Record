//
// Created by Administrator on 2020/5/8 0008.
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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head){
            res = res*2 + head->val;
            head = head->next;
        }
        return res;
    }
};