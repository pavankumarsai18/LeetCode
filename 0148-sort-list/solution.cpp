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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        
        ListNode* cur = head;
        while(cur)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        
        sort(nums.begin(), nums.end());
        
        int curIndex = 0;
        cur = head;
        while(cur)
        {
            cur->val = nums[curIndex++];
            cur = cur->next;
        }
        
        return head;
        
    }
};
