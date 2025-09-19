/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else if(l2->val < l1->val){
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;

                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* curr = merge(lists[0], lists[1]);
        for(int i=2;i<lists.size();i++){
            curr = merge(curr, lists[i]);
        }
        return curr;
    }
};