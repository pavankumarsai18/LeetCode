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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) 
    {
        unordered_set<int> duplicates;
        unordered_map<int, int> numCount;
        ListNode* cur  = head;
        
        while(cur)
        {
            numCount[cur->val]++;
            cur = cur->next;
        }
        
        for(auto & [num, count]: numCount)
        {
            if(count > 1) duplicates.insert(num);
        }
        
        numCount.empty();
        
        ListNode* newHead = new ListNode();
        newHead->next     = head;
        ListNode* prev    = newHead;        
        cur = head;

        while(cur)
        {
            ListNode* nextNode = cur->next;
            if(duplicates.find(cur->val) != duplicates.end())
            {
                prev->next = cur->next;
                cur->next = nullptr;   
            } 
            else
            {
                prev = cur;
            }
            cur  = nextNode;
        }
        

        return newHead->next;
        
        
    }
};
