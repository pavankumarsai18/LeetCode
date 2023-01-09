class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        def hash(string: str)->str:
            ans = ""
            for ch in string:
                # ord(ch) < ord(string[0])
                ans += str(26 + ord(ch) - ord(string[0]) if ord(ch) < ord(string[0]) else ord(ch) - ord(string[0]))
                ans += " "
            return ans
        
        shiftedStrings = collections.defaultdict(list)

        for string in strings:
            # print(f"hash {hash(string)} string string")
            shiftedStrings[hash(string)].append(string)
        
        ans = []
        for key, value in shiftedStrings.items():
            ans.append(value)
        return ans

