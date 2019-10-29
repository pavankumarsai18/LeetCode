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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Stratergy at the end of the day
        // the we can start from the end of the Y road >- 
        // that it the tail for both the list should be the same
        // so we back track till the tails differ
        // and the last common node is the intersection Node.
        // so it going to take O(n) --> space and O(n) --> time
        
        //OR we perform a dfs till we either hit the intersection node or a nullptr

        
        // SMART ONE a two pass algo
        auto curr_A = headA;
        auto curr_B = headB;
        
        int size_A = 0;
        int size_B = 0;
        
        while(curr_A != nullptr)
        {size_A ++;
        curr_A = curr_A -> next;}
        
        while(curr_B != nullptr)
        {size_B ++;
        curr_B = curr_B -> next;}
        
        curr_A = headA;
        curr_B = headB;
        
        if(size_A > size_B)
        {for(int i = 0; i < size_A - size_B; i++)
                curr_A = curr_A->next;}
        
        else if(size_B > size_A)
        {for(int i = 0; i < size_B - size_A; i++)
                curr_B = curr_B -> next;}
        
        while(curr_A != nullptr || curr_B != nullptr)
        {   if(curr_A == curr_B)
                break;
            curr_A = curr_A->next;
            curr_B = curr_B-> next;
        }
        
        return curr_A;
    }
};
