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
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        
        ListNode* cur1   = list1;
        ListNode* cur2   = list2;
        ListNode* result = nullptr;
        ListNode* cur    = nullptr;
        
        if(cur1->val < cur2->val)
        {
            result = cur1;
            cur    = cur1;
            cur1 = cur1->next;
        }
        else
        {
            result = cur2;
            cur    = cur2;
            cur2 = cur2->next;
        }
        
        while(cur1 && cur2)
        {
            if(cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        
        ListNode* head = (cur1 != nullptr)? cur1: cur2;
        cur->next = head;
    
        return result;
    }
    
    ListNode* divideAndMerge(vector<ListNode*>& lists, int start, int end)
    {
        if(start > end)
        {
            return nullptr;
        }
        
        if(start == end)
        {
            return lists[start];
        }
        else if(end == start + 1)
        {
            return merge(lists[start], lists[end]);
        }
        
        int mid =  (start + end)/2;
        ListNode* l1 = divideAndMerge(lists, start, mid);
        ListNode* l2 = divideAndMerge(lists, mid+1, end);
        
        return merge(l1, l2);
    
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        const int n = lists.size();
        int start = 0;
        int end   = n-1;
        return divideAndMerge(lists, start, end);
        
    }
};
