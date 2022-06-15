class Solution:    
    def minWindow(self, text, pattern):
        patternCount   = defaultdict(int)
        remainingChars = len(pattern)
        patternChars   = [False]*56
        for ch in pattern:
            patternCount[ch] += 1
            
            index = ord(ch) - ord('a')
            if ch.isupper():
                index = ord(ch) - ord('A')
            patternChars[index] = True
            
        ansLeft, ansRight = 0,0
        minLength         = float('inf')
        
        left = 0
        for right, ch in enumerate(text):
            index = ord(ch) - 97
            
            if index < 0:
                index = ord(ch) - 65
            
            if patternChars[index]:
                if patternCount[ch] > 0:
                    remainingChars -= 1
                patternCount[ch] -= 1
            
                if remainingChars == 0:
                    while True:
                        ch = text[left]
                        if ch in patternCount:
                            if patternCount[ch] == 0:
                                break
                            else:
                                left += 1
                                patternCount[ch] += 1
                        else:
                            left += 1
                
                    length = right - left + 1
                    if length < minLength:
                        minLength = length
                        ansLeft, ansRight = left, right
                
                    patternCount[text[left]] = 1
                    remainingChars           = 1
                    left += 1

        return text[ansLeft:ansRight+1] if minLength < float('inf') else ""
                    
