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
    int getDecimalValue(ListNode* head) 
    {
        
        int result = 0;
        auto cur = head;
        
        while(cur != nullptr)
        {
            result += cur->val;
            result <<= 1;
            cur = cur->next;
        }
        result >>= 1;
        return result;
    }
};
