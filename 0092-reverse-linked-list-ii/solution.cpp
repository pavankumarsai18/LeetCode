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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        
        if(left == right)
            return head;
        ListNode* lo = head; ListNode* hi = head; ListNode* cur = head;
        
        stack<ListNode*> S;
        
        int count = 1;
        while(count <= right && cur != nullptr)
        {
            if(count <= left)
            {
                lo = cur;
                if(count == left)
                    S.push(cur);
            }
            else
            {
                
                S.push(cur);
                hi = cur;
            }
            count++;
            cur = cur->next;
        }

        hi = S.top();S.pop();
        int length = right - left + 1;
        count = 0;
        while(count < length/2)
        {
            int temp = lo->val;
            lo->val = hi->val;
            hi->val = temp;
            
            lo = lo->next;
            hi = S.top();S.pop();
            count++;
        }
        return head;
        
    }
};
