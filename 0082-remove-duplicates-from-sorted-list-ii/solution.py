# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        resultList = ListNode()
        
        curPtr = None
        
        prevNode = None
        curNode = head
        
        while curNode:
            temp = curNode
            while temp.next != None and temp.val == temp.next.val:
                prevNode = temp
                temp = temp.next
            curNode = temp
            
            # if prevNode:
            #     print(curNode.val, prevNode.val)
            # else:
            #     print(curNode.val, "None")
            
            if prevNode == None and curNode:
                if (curNode.next and curNode.next.val != curNode.val) or (curNode.next == None):
                    if curPtr:
                        curPtr.next = ListNode(curNode.val)
                        curPtr = curPtr.next
                    else:
                        curPtr = resultList
                        curPtr.val = curNode.val                    
                    
            
            elif curNode and prevNode:
                if curNode.next and curNode.next.val != curNode.val != prevNode.val:
                    if curPtr:
                        curPtr.next = ListNode(curNode.val)
                        curPtr = curPtr.next
                    else:
                        curPtr = resultList
                        curPtr.val = curNode.val
                elif curNode.next == None:
                    if curNode.val != prevNode.val:
                        if curPtr:
                            curPtr.next = ListNode(curNode.val)
                            curPtr = curPtr.next
                        else:
                            curPtr = resultList
                            curPtr.val = curNode.val
                        
            if curNode:
                prevNode = curNode
                curNode = curNode.next
         
        return None if curPtr == None else resultList
