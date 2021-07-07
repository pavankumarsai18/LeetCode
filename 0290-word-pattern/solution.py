class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        words = s.split(' ')
        char_word, word_char = dict(), dict()
        
        if len(words) != len(pattern):
            return False
        
        for i in range(len(pattern)):
            if pattern[i] in char_word:
                if char_word[pattern[i]] != words[i]:
                    return False
            else:
                char_word[pattern[i]] = words[i]
                if words[i] not in word_char:
                    word_char[words[i]] = pattern[i]
                elif word_char[words[i]] != pattern[i]:
                    return False
            
            if words[i] in word_char:
                if word_char[words[i]] != pattern[i]:
                    return False
            else:
                word_char[words[i]] = pattern[i]
                if pattern[i] not in char_word:
                    char_word[pattern[i]] = words[i]
                elif char_word[pattern[i]] != words[i]:
                    return False
        
        return True
