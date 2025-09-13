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

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nn = head->next;
            head->next = prev;
            prev = head;
            head = nn;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* A = reverse(l1);
        // ListNode* B = reverse(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        while(ptr1 && ptr2){
            int sum = ptr1->val + ptr2->val;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(carry) sum += carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;
        }
    
        while(ptr1){
            int sum = 0;
            if(carry) sum = ptr1->val + carry;
            else sum = ptr1->val;
            ptr1 = ptr1->next;
            carry = sum/10;
            ListNode* temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;
        }
    
        while(ptr2){
            int sum = 0;
            if(carry) sum = ptr2->val + carry;
            else sum = ptr2->val;
            ptr2 = ptr2->next;
            carry = sum/10;
            ListNode* temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;
        }
        
        if(carry){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = curr->next;
        }

        // ListNode* ans = reverse(dummy->next);
        return dummy->next;
    }
};