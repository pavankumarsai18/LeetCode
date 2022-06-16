class Solution:
    def lengthOfLongestSubstringKDistinct(self, text: str, k: int) -> int:
        if k == 0:
            return 0
        
        charCount         = defaultdict(int)
        ansLeft, ansRight = 0,0
        maxLength         = 0
        left              = 0
        
        
        for right, ch in enumerate(text):
            
            charCount[ch]+=1
            if len(charCount) == k+1:
                while len(charCount) != k:
                    charCount[text[left]] -= 1
                    if charCount[text[left]] == 0:
                        del charCount[text[left]]
                    left += 1
                                
            if maxLength < right-left+1:
                maxLength = right-left+1
                
        return maxLength
