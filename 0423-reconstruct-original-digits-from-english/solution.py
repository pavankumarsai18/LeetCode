class Solution(object):
    def countDigits(self, UniqueChar, numCount, charCount):
        digitWord = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
        for i in xrange(len(UniqueChar)):
            word = UniqueChar[i]
            if word in charCount:
                temp = charCount[word]
                for c in digitWord[i]:
                    if c not in charCount:
                        temp = 0
                        break
                numCount[i] += temp
                if temp != 0:
                    for c in digitWord[i]:
                        charCount[c] -= temp

    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        charCount = dict()
        for char in s:
            if char in charCount:
                charCount[char] += 1
            else:
                charCount[char] = 1
        
        numCount = [0 for _ in range(10)]

        uniqueChar = ["z","", "w","", "u","", "x","", "g",""]
        self.countDigits(uniqueChar, numCount, charCount)
        # remaining 1, 3, 5, 7, 9
        uniqueChar = ["","o", "","h", "","f", "","v", "","i"]
        self.countDigits(uniqueChar, numCount, charCount)
        result = ""
        for i in xrange(len(numCount)):
            for j in xrange(numCount[i]):
                result += str(i)
        return result
            
                
            
