# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:        
        cur      = head
        evenHead = ListNode(-1)
        curEven  = evenHead
        
        while cur:
            oddNode  = cur
            evenNode = cur.next
            
            if evenNode:
                oddNode.next  = evenNode.next
                evenNode.next = None
            else:
                oddNode.next  = None
                
            if evenNode:
                curEven.next  = evenNode
                curEven       = curEven.next
                           
            if oddNode.next:
                cur = oddNode.next
            else:
                cur.next = evenHead.next
                break
            
        
        return head
