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
    bool isPalindrome(ListNode* head) {
        
        int size = 0;
        auto curr = head;
        stack<int> S;
        while(curr != nullptr)
        {
            size++;
            curr=curr->next;
        }
        
        curr = head;
        for(int i = 0; i < size/2; i++)
        {
            S.push(curr->val);
            curr = curr->next;
        }
        if(size%2)
            curr = curr->next; // we skip over the middle element
        // pop the stack and we compare till we reach the tail
        while(curr != nullptr)
        {
            if(S.top() != curr->val)
                return false;
            curr = curr->next;
            S.pop();
        }
        return true;
        
        
        //we can create a reverse linked list and compare the nodes
        // one by one O(n) --> space O(n) --> time
        
        //we can traverse half the linked list and while
        //traversing we can add elements into a stack
        // after we reach the middle element we popthe stack and compare the
        // values  O(n) --> space O(n) --> time
        
        
        // we could split the linked list in half and reverse
        // the second linked list and compare it one by one
        // and if we wanted we could again reverse the scond linked list
        // and attach it to the first linked list and return it
        // O(n) --> time O(1) --> space
        // O(n/2) --> comparisions and O(n/2) to reverse it and O(n/2) to reverse it
        // again so O(3n/2)
        
        
        
        
    }
};
