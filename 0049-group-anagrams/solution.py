class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        def hashValue(word):
            
            
            return str(num_count)
        
        anagrams = defaultdict(list)
        
        for word in strs:
            num_count = [0 for _ in range(26)]
            
            for ch in word:
                num_count[ord(ch)-ord('a')] += 1
            anagrams[tuple(num_count)].append(word)

        
        return anagrams.values()
