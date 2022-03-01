class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        
        S = collections.deque()
        
        for i in xrange(len(tokens)):
            if tokens[i] == "+":
                a = int(S.popleft())
                b = int(S.popleft())
                S.appendleft(a+b)
            elif tokens[i] == "-":
                a = int(S.popleft())
                b = int(S.popleft())
                S.appendleft(b-a)
            elif tokens[i] == "*":
                a = int(S.popleft())
                b = int(S.popleft())
                S.appendleft(b*a)
            elif tokens[i] == "/":
                a = float(S.popleft())
                b = float(S.popleft())
                S.appendleft(int(b/a))
            else:
                S.appendleft(tokens[i])
        
        return int(S.popleft())
