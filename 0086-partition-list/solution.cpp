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
    ListNode* partition(ListNode* head, int x) 
    {
        
        ListNode* less;
        ListNode* lessHead;
        
        ListNode* greater;
        ListNode* greaterHead;
        
        less = lessHead = new ListNode();
        
        greater = greaterHead = new ListNode();
        
        ListNode* cur = head;
        while(cur)
        {
            if(cur->val < x)
            {
                
                less->next = cur;
                less = less->next;
                cur = cur->next;
                
                less->next = nullptr;
            }
            else
            {
                greater->next = cur;
                greater = greater->next;
                cur = cur->next;
                
                greater->next = nullptr;
            }
        }
        
        less->next = greaterHead->next;
        
        greaterHead->next = nullptr;
        
        return lessHead->next;
        
        
    }
};
