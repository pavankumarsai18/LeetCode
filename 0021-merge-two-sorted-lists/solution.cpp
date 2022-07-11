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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);;
        ListNode* cur  = head; 
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
            
        while(cur1 != nullptr && cur2 != nullptr)
        {
            if(cur2->val < cur1->val)
            { 
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
        
            cur = cur->next;
        }
        if(cur1)
        {
            cur->next = cur1;
        }
        else
        {
            cur->next = cur2;
        }
        return head->next;
    }
};
