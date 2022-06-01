# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        if not head:
            return
        
        slow, fast = head, head
        
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        
        
        # reverse in place
        prev, cur = None, slow
        while cur:
            cur.next, cur, prev = prev, cur.next, cur
        
        # Merge
        first, second = head, prev
        while second.next:
            first.next, first   = second, first.next
            second.next, second = first, second.next
