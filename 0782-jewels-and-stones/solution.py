class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        is_present = {}
        for char in J:
            if char not in is_present:
                is_present[char] = True

        result = 0
        for jewel in S:
            if jewel in is_present:
                result += 1
        return result
