class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[len(digits) - 1] += 1
        if digits[len(digits) - 1] <= 9:
            return digits
        else:
            i = len(digits) - 1
            while i >= 0:
                if i - 1 >= 0 and digits[i] == 10:
                    digits[i] = 0
                    digits[i-1] += 1
                i -= 1
            if digits[0] == 10:
                result = [None]*(len(digits) + 1)
                for i in range(len(digits)):
                    result[i+1] = digits[i]
                result[1] = 0
                result[0] = 1
                return result
            else:
                return digits
                    
