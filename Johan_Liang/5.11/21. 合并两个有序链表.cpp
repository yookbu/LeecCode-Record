//21. 合并两个有序链表
// Created by Administrator on 2020/5/11 0011.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                if(l1->val < l2->val){
                    head->next = l1;
                    l1 = l1->next;
                    head = head->next;
                }else{
                    head->next = l2;
                    l2 = l2->next;
                    head = head->next;
                }
            }
            if(l1 == NULL && l2 !=NULL){
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
            if(l2 == NULL && l1 != NULL){
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
        }
        return res->next;
    }
};