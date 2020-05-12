//
// Created by Administrator on 2020/5/9 0009.
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
    int length(ListNode* l1){
        if(l1 == NULL){
            return 0;
        }else{
            return 1 + length(l1->next);
        }
    }
    int helper(ListNode* l1, ListNode* l2, ListNode* &res){
        if(l1 == NULL || l2 == NULL){
            return 0;
        }else{
            int sum = l1->val + l2->val + helper(l1->next, l2->next, res);
            ListNode* temp = new ListNode(sum%10);
            temp->next = res;
            res = temp;
            return sum/10;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = length(l1);
        int l2_len = length(l2);
        int carry = 0;
        ListNode* res = nullptr;
        if(l1_len > l2_len){
            ListNode* head = new ListNode(-1);
            head->next = l2;
            for(int i = 0; i < (l1_len - l2_len); ++i){
                ListNode* temp = new ListNode(0);
                temp->next = head->next;
                head->next = temp;
            }
            carry = helper(l1, head->next, res);
        }
        else if(l2_len > l1_len){
            ListNode* head = new ListNode(-1);
            head->next = l1;
            for(int i = 0; i < (l2_len - l1_len); ++i){
                ListNode* temp =new ListNode(0);
                temp->next = head->next;
                head->next = temp;
            }
            carry = helper(head->next, l2, res);
        }
        else{
            carry = helper(l1, l2, res);
        }

        if(carry){
            ListNode* temp = new ListNode(1);
            temp->next = res;
            res = temp;
        }
        return res;
    }
};

















