class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = deque()
        removeIndices = set()
        
        for i in range(len(s)):
            if s[i] == ')':
                if len(stack) > 0:
                    stack.pop()
                else:
                    removeIndices.add(i)
                    
            elif s[i] == '(':
                stack.append((s[i], i))
        
        
        while len(stack):
            c, index = stack.pop()
            removeIndices.add(index)
        
        result = []
        for i in range(len(s)):
            if i not in removeIndices:
                result.append(s[i])
        return "".join(result)
                
            
