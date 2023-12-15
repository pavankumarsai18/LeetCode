class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()

        for word in strs:
            sorted_word = "".join(sorted([c for c in word]))

            if sorted_word not in anagrams:
                anagrams[sorted_word] = list()
            
            anagrams[sorted_word].append(word)

        
        return anagrams.values()


