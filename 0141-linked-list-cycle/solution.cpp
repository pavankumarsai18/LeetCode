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
    bool hasCycle(ListNode *head) 
    {
        ListNode* rabbit   = head;
        ListNode* tortoise = head;
        
        while(rabbit != nullptr && tortoise != nullptr)
        {
            
            
            rabbit = rabbit->next;
            if(rabbit == nullptr)
            {
                return false;
            }
            
            rabbit = rabbit->next;
            tortoise = tortoise->next;
            if(rabbit == tortoise)
            {
                return true;
            }
        }
        
        return false;
        
        
        
        
    }
};
