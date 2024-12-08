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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* sum_list_ptr = dummy;
        
        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;
        
        int carry = 0;
        while (l1_ptr || l2_ptr) {
            
            int val1 = 0;
            int val2 = 0;
            
            if (l1_ptr != nullptr) {
                val1 = l1_ptr->val;
                l1_ptr = l1_ptr->next;
            }
            
            if (l2_ptr != nullptr) {
                val2 = l2_ptr->val;
                l2_ptr = l2_ptr->next;
            }
            
            int sum = val1 + val2 + carry;
            carry = (sum/10);
            int digit = sum % 10;
            
            sum_list_ptr->next = new ListNode(digit);
            sum_list_ptr = sum_list_ptr->next;
        }
        
        if (carry) {
            sum_list_ptr->next = new ListNode(carry);
        }
        
        return dummy->next;
    
    }
};
