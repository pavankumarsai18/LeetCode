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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* dummy = new ListNode(1);
        dummy->next = head;
        
        
        int n = 0;
        ListNode* cur = head;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
        
        int idx = 0;

        ListNode* prev = dummy;
        cur = head;
        while(idx != n/2)
        {
            cur = cur->next;
            prev = prev->next;
            idx++;
        }
        
        prev->next = cur->next;
        cur->next = nullptr;
        
        return dummy->next;
    }
};
