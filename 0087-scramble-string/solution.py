class Solution:
    def scramble(self, text: str, target:str, cache: dict[tuple[str,str],bool])->bool:
        if (text, target) in cache:
            return cache[(text, target)]
        
        if len(text) == 1:
            return text == target
        
        charCount1 = [0]*26
        charCount2 = [0]*26
        for ch1, ch2 in zip(text, target):
            charCount1[ord(ch1)-ord('a')] += 1
            charCount2[ord(ch2)-ord('a')] += 1
        if charCount1 != charCount2:
            cache[(text, target)] = False
            return False
        
        for i in range(len(text)):
            first  = text[:i]
            second = text[i:]
            if self.scramble(first, target[:i], cache) and self.scramble(second, target[i:], cache):
                cache[(text, target)] = True
                return True
            if self.scramble(first, target[-i:], cache) and self.scramble(second, target[:-i], cache):
                cache[(text, target)] = True
                return True
        cache[(text, target)] = False
        return False
            
            
    def isScramble(self, s1: str, s2: str) -> bool:
        cache = defaultdict(bool)
        return self.scramble(s1, s2, cache)
