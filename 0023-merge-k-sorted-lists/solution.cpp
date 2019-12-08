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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<ListNode*> curr;
        for(auto x : lists)
            curr.push_back(x);
        
        ListNode* result = nullptr;
        ListNode* curr_node = nullptr;
        int end_reached = 0;
        while(end_reached != lists.size())
        {
            int index = 0;
            bool count = false;

            for(int i = 0; i < curr.size(); i++)
            {
                if(curr[i] != nullptr && count == false)
                {
                    index = i;
                    count = true;
                }
                else if(curr[i] != nullptr)
                {
                    if(curr[index]->val > curr[i]->val)
                    {
                        index = i;
                    }
                }

            }
            // cout<<curr[index]->val<<" ";
           
            // cout<<curr[index]->val<<" ";
            if(curr[index] == nullptr)
            {
                end_reached ++;
            }
            else
            {
                if(result == nullptr)
                {
                    result = new ListNode(curr[index]->val);
                    curr_node = result;
                }
                else
                {
                    auto temp =  new ListNode(curr[index]->val);
                    curr_node->next = temp;
                    curr_node = curr_node->next;
                }
                curr[index] =  curr[index]->next;
            }
             
        }
        return result;
        
        
     }
    
};
