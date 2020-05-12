//25. K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 0) return head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead;
        stack<ListNode*> s;
        while(cur->next){
            for(int i = 0; i < k && cur->next; ++i){
                s.push(cur->next);
                cur = cur->next;
            }
            if(s.size()<k) break;
            ListNode* nextStart = cur->next;
            ListNode* start = pre;
            while(!s.empty()){
                ListNode* node = s.top();
                s.pop();
                start->next = node;
                start = start->next;
            }
            start->next = nextStart;
            pre = start;
            cur = start;
        }
        return dummyHead->next;
    }
};