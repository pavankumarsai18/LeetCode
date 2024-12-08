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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* merged_list_ptr = dummy;
        
        while (list1 || list2) {
            int val1 = (list1) ? list1->val : INT_MAX;
            int val2 = (list2) ? list2->val : INT_MAX;
            if (val1 <= val2) {
                merged_list_ptr->next = list1;
                ListNode* temp = list1->next;
                list1->next = nullptr;
                list1 = temp;
            } else {
                merged_list_ptr->next = list2;
                ListNode* temp = list2->next;
                list2->next = nullptr;
                list2 = temp;
            }
            
            merged_list_ptr = merged_list_ptr->next;
        }
        
        return dummy->next;
        
    }
};
