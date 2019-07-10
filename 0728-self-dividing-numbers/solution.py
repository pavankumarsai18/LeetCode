class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result = []
        for num in range(left, right + 1):
            temp = num
            count = 0
            while temp != 0:
                digit = temp%10
                if digit == 0 or num%digit != 0:
                    break
                else:
                    count += 1
                temp //= 10
            if num//pow(10, count) == 0:
                result.append(num)
        return result
