class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        abbrIndex = 0
        wordIndex = 0
        while abbrIndex < len(abbr) and wordIndex < len(word):
            if abbr[abbrIndex].isalpha():
                if abbr[abbrIndex] == word[wordIndex]:
                    abbrIndex += 1
                    wordIndex += 1
                else:
                    return False
            elif abbrIndex < len(abbr) and abbr[abbrIndex].isdigit():
                num = ""
                while abbrIndex < len(abbr) and abbr[abbrIndex].isdigit():
                    num += abbr[abbrIndex]
                    abbrIndex += 1
                if num[0] == "0":
                    return False
                wordIndex += int(num)
        
        return (abbrIndex == len(abbr) and wordIndex == len(word))
