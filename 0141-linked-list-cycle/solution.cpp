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
    bool hasCycle(ListNode *head) {
        
        //make a map 
        map<ListNode*, int> p_count;
        
        //vector<ListNode*>p;
        while(head != 0)
        {
            if(p_count.find(head) != p_count.end())
            {
                p_count[head] += 1;
                if(p_count[head] > 1)
                    return true;
            }
            else
                p_count[head] = 0;
            head = head->next;
        }
        return false;
        
    }
};
