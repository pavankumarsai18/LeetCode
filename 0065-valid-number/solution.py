class Solution(object):
    def parseInteger(self, s):
        # print("parseInt", s)
        if s == '':
            return False
        i = 0
        # If the string starts with a + or -
        if s[i] == "+" or s[i] == '-':
            i += 1
        # All other numbers should be digits
        if i < len(s) and s[i].isdigit():
            while i < len(s) and s[i].isdigit():
                i += 1
            if i == len(s):
                return True
            return False

        return False
    
    def parseDecimal(self, s):
        # print("parseDecimal", s)
        integer, fractional = '', ''
        if s == '':
            return False
        
        if s[0] == "+" or s[0] == '-':
            s = s[1:]
        
        if s == '':
            return False
        
        if s[0].isdigit() or s[0] == '.':
            split = s.split('.')
            # print(split)
            if len(split) > 2 or len(split) == 0:
                return False
            
            elif len(split) == 1:
                if s[0] != '.':
                    integer = split[0]
                else:
                    fractional = split[0]
            else:
                integer, fractional = split[0], split[1]
            
            if integer == '' and fractional == '':
                return False
            
            
            isValid = True

            if integer != '':
                isValid = self.parseInteger(integer)

            if fractional != '':
                if fractional[0].isdigit():
                    isValid = isValid and self.parseInteger(fractional)
                else:
                    isValid = False
            return isValid
        
        return False
            
    def parseExponential(self, s):
        if len(s) > 0 and s[0] == 'e' or s[0] == 'E':
            s = s[1:]
            return self.parseInteger(s)
        
        return False
            
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # print(s)
        if 'e' in s or 'E' in s:
            i = 0
            while i < len(s):
                if s[i] == 'e' or s[i] == 'E':
                    break
                i += 1
                
            nonExp, exp = s[:i], s[i:]
            # print((self.parseInteger(nonExp) or self.parseDecimal(nonExp)) and self.parseExponential(exp))
            return (self.parseInteger(nonExp) or self.parseDecimal(nonExp)) and self.parseExponential(exp)
        
        # print(self.parseInteger(s) or self.parseDecimal(s))
        return self.parseInteger(s) or self.parseDecimal(s)
