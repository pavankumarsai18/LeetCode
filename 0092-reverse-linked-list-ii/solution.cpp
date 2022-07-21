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
    void print(ListNode* leftNode)
    {
        ListNode* cur = leftNode;
        while(cur)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    void reverse(ListNode* & leftNode, ListNode* & rightNode)
    {
        ListNode* tail = leftNode;
        ListNode* cur = leftNode;
        ListNode* nextNode;
        ListNode* prev;
        
        prev = nullptr;
        
        while(cur)
        {
            nextNode  = cur->next;
            
            cur->next = prev;
            prev      = cur;
            
            cur = nextNode;
        }
        
        leftNode  = prev;
        rightNode = tail;
        return; 
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        
        ListNode* prev;
        ListNode* leftNode;
        ListNode* rightNode;
        ListNode* cur;
        ListNode* leftPrev;
        ListNode* rightNext;
        
        int pos = 1;
        
        cur = head; 
        leftNode = rightNode = prev = nullptr;
        
        while(cur != nullptr)
        {
            if(pos == left)
            {
                leftPrev = prev;
                leftNode = cur;
            }
            if(pos == right)
            {
                rightNode = cur;
                rightNext = rightNode->next;
                break;
            }
            
            pos++;
            prev = cur;
            cur  = cur->next;
        }
        
        if(leftPrev) leftPrev->next = nullptr;
        rightNode->next = nullptr;
        
        // cout<<"unreversed ";
        // print(leftNode);
        
        reverse(leftNode, rightNode);
        // cout<<"reversed ";
        // print(leftNode);
        
        if(leftPrev) leftPrev->next = leftNode;
        if(rightNext) rightNode->next = rightNext;
        
        // cout<<"head ";
        // print(head);
        head = (left == 1)? leftNode:head;
        
        return head;
    }
};
