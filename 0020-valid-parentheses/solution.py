class Solution:
    def __init__(self):
        self.stack = []
    
    def pop(self):
        return self.stack.pop()
    
    def top(self):
        return self.stack[-1]
    
    def push(self, value):
        self.stack.append(value)
        
    def isValid(self, s: str) -> bool:
        result = False
        
        for bracket in s:
            if bracket in ["(", "{", "["]:
                self.push(bracket)
            else:
                if len(self.stack) == 0:
                    return False
                t = self.pop()
                if (t == "{" and bracket != "}") or ( t == "[" and bracket != "]") or (t == "(" and bracket != ")"):
                    return False
        if len(self.stack) != 0:
            return False
        else:
            return True
        
