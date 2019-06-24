class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        count = {}
        for letter in s:
            if letter not in count:
                count[letter] = 1
            else:
                count[letter] += 1
        #print(count)
        for letter in t:
            if letter in count:
                if count[letter] > 0:
                    count[letter] -= 1
                else:
                    return False
            else:
                return False
        for key in count:
            if count[key] != 0:
                return False
        return True
                
