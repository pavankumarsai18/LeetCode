class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
                                
        # we start at the end of the string
        # we iterate till we find a non white space char or reach the beginning of the string
        # if we reach the beginning of the string without an non white space char then we return 0
        # if we find a non white space character then we break out of the loop
        # and we start from that index and iterate till we find a whit space char 
        # or we reach the begging of the string we keep the counter and increment the length
        # if we reach the beginnig of the string then we break and return the length
        
        index = len(s) - 1
        while index >= 0:
            if s[index] != " ":
                break
            elif index == 0 and s[index] == " ":
                return 0
            index -= 1
        # length of the last word
        l = 0
        
        while index >= 0:
            if s[index] == " ":
                break
            elif s[index] != " ":
                l += 1
            index -= 1
        return l

        
