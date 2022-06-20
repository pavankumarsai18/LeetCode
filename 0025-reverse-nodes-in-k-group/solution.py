# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
        
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        
        groupPrev = dummy
        
        def getKth(node, k):
            cur = node
            while cur and k > 0:
                cur = cur.next 
                k -= 1
            return cur
        
        
        while True:
            kth = getKth(groupPrev, k)
            if not kth:
                break
            
            groupNext = kth.next
            prev, cur = groupNext, groupPrev.next
            
            # Reverse K nodes
            while cur != groupNext:
                temp     = cur.next
                cur.next = prev
                prev     = cur
                cur      = temp
            #*******
            # After reversal prev will have head of reversed nodes
            # groupPrev should point to the new tail of reversed nodes which is kth
            # groupPrev.next will hold the last
            temp           = groupPrev.next
            groupPrev.next = kth
            groupPrev      = temp
        
        return dummy.next
            
            
        
        
