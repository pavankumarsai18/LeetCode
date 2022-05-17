# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return "None"
        
        return str(root.val) + ",["+ self.serialize(root.left)+ "],[" + self.serialize(root.right) + "]"
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        
        root = None
        # print(data)
        if data == "None":
            return root
        
        curIndex = 0
        val = ""
        while curIndex < len(data) and data[curIndex] != ',':
            val += data[curIndex]
            curIndex += 1
        
        root = TreeNode(int(val))
        
        val = ""
        curIndex += 1
        stack = deque()
        stack.append(data[curIndex])
        curIndex += 1
        # print(stack, curIndex)
        while len(stack) and curIndex < len(data):
            # print(stack, curIndex)
            if data[curIndex] == '[':
                stack.append('[')
            elif data[curIndex] == ']':
                stack.pop()
            if len(stack) != 0:
                val += data[curIndex]
            curIndex += 1
        
        # print("left tree", val)
        root.left = self.deserialize(val)
        
        val = ""
        curIndex += 1
        stack = deque()
        stack.append(data[curIndex])
        curIndex += 1
        while len(stack) and curIndex < len(data):
            if data[curIndex] == '[':
                stack.append('[')
            elif data[curIndex] == ']':
                stack.pop()
            if len(stack) != 0:
                val += data[curIndex]
            curIndex += 1
        # print("right tree", val)
        root.right = self.deserialize(val)
        
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
