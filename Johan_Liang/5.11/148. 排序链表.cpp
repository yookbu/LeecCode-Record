//
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
    ListNode* sortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead->next;
        int length = 0;
        while(p){
            ++length;
            p = p->next;
        }
        for(int i = 1; i < length ; i <<= 1){
            ListNode* cur = dummyHead->next;
            ListNode* tail = dummyHead;
            while(cur){
                ListNode* left = cur;
                ListNode* right = cut(cur, i);
                cur = cut(right, i);

                tail->next = merge(left, right);
                while(tail->next){
                    tail = tail->next;
                }
            }
        }
        return dummyHead->next;
    }

    ListNode* cut(ListNode* l, int span){
        while(--span && l){
            l = l->next;
        }
        if(!l){
            return nullptr;
        }
        ListNode* remain = l->next;
        l->next = NULL;
        return remain;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        while(left && right){
            if(left->val < right->val){
                p->next = left;
                left = left->next;
                p = p->next;
            }else{
                p->next = right;
                right = right->next;
                p = p->next;
            }
        }
        p->next = left ? left : right;
        return dummyHead->next;
    }
};
