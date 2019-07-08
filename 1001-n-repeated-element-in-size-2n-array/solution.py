class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        num_count = {}
        for num in A:
            if num not in num_count:
                num_count[num] = 1
            else:
                return num
