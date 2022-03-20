class Solution(object):
    def hasBraces(self, s):
        sqBraces = False
        for i in xrange(len(s)):
            if s[i] == "[" or s[i] == "]":
                sqBraces = True
                break
        return sqBraces
    
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if self.hasBraces(s) == False:
            return s
        
        result = ""
        numbers = []
        expressions = []
        i = 0
        while i < len(s):
            number = ""
            expression = ""
            stack = 0
            
            while i < len(s) and s[i].isalpha():
                expression += s[i]
                i += 1
            
            if expression:
                number = 1
                numbers.append(number)
                expressions.append(expression)
                continue
                
            while i < len(s) and s[i].isdigit():
                number += s[i]
                i += 1
                
            if i < len(s) and s[i] == "[":
                numbers.append(int(number))
                stack += 1
                i += 1
            
            while i < len(s) and stack != 0:
                if s[i] == "[":
                    expression += s[i]
                    stack += 1
                elif s[i] == "]":
                    stack -= 1
                    if stack > 0:
                        expression += s[i]
                    else:
                        expressions.append(expression)
                        break
                else:
                    expression += s[i]
                i += 1
            i += 1
        result = ""
        for i in xrange(len(expressions)):
            expr = expressions[i]
            decodedExpr = expr
            if self.hasBraces(expr):
                decodedExpr = self.decodeString(expr)
            for _ in xrange(int(numbers[i])):
                result += decodedExpr
        return result                            
            
            
                
