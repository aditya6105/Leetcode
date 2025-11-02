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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(auto it : nums) s.insert(it);
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        prev->next = head;
        while(curr){
            if(s.count(curr->val)){
                if(curr == head) head = head->next;
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};