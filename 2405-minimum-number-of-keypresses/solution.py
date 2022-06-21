class Solution:
    def minimumKeypresses(self, text: str) -> int:
        charCount  = defaultdict(int)
        for ch in text:
            charCount[ch] += 1
        
        if len(charCount) <= 9:
            return len(text)
        
        numCharsVisited = 0
        keyboard = [list() for _ in range(9)]
        
        index = 0
        keyPresses = 0
        for char in sorted(charCount, key=charCount.get, reverse=True):
            index = (numCharsVisited)//9
            for num in range(1, 10):
                if len(keyboard[num-1]) <= index:
                    keyPresses += charCount[char]*(index+1)
                    keyboard[num-1].append(char)
                    break
            numCharsVisited += 1
               
        return keyPresses
            
        
        
        
