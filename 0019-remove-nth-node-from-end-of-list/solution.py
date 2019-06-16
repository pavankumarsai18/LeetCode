# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:            
        if head.next == None and n == 1:
            return None
        length = 0
        node = head
        while node.next != None:
            length += 1
            node = node.next
        print(length)
        if length == n - 1:
            head = head.next
            return head
            
        temp = 0
        cur_node = head
        while temp < length - n:
            temp += 1
            cur_node = cur_node.next
        next_node = cur_node.next
        cur_node.next = next_node.next
        next_node.val = None
        return head
