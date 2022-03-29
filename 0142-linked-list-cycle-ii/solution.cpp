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
    ListNode *detectCycle(ListNode *head) 
    {
        
        ListNode* tortoise;
        ListNode* hare;
        
        
        tortoise = hare = head;
        
        do
        {
            if(tortoise == nullptr || hare == nullptr)
            {
                return nullptr;
            }
            tortoise = tortoise->next;
            hare = hare->next;
            if(tortoise == nullptr || hare == nullptr)
            {
                return nullptr;
            }
            hare = hare->next;
            
        }while(tortoise != hare);
        
        
        tortoise = head;
        while(tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        return hare;
        
        
        
    }
};
