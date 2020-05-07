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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];

        return helper(lists, 0, lists.size()-1);
    }

    ListNode* helper(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];
        int mid = (start+end)/2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid+1, end);
        ListNode* dummyHead = new ListNode(-1);
        ListNode* head = dummyHead;
        while(left && right){
            if(left->val < right->val){
                head->next = left;
                head = head->next;
                left = left->next;
            }else if(left->val > right->val){
                head->next = right;
                head = head->next;
                right = right->next;
            }else{
                head->next = left;
                head = head->next;
                left = left->next;
                head->next = right;
                head = head->next;
                right = right->next;
            }
        }
        if(left){
            head->next = left;
        }
        if(right){
            head->next = right;
        }
        return dummyHead->next;
    }
};