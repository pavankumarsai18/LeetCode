class Solution:
    def buddyStrings(self, text: str, target: str) -> bool:
        if len(text) != len(target):
            return False
        
        if text == target:
            charCount = defaultdict(int)
            for ch in text:
                charCount[ch] += 1
                if charCount[ch] >= 2:
                    return True
            return False
        
            
        
        textCh1, textCh2 = None, None
        targetCh1, targetCh2 = None, None
        for ch1, ch2 in zip(text, target):
            if ch1 != ch2:
                if not textCh1:
                    textCh1 = ch1
                    targetCh1 = ch2
                elif not textCh2:
                    textCh2 = ch1
                    targetCh2 = ch2
                else:
                    return False
        
        
        return (textCh1 and textCh2) and (textCh1 == targetCh2) and (textCh2 == targetCh1)
                    
