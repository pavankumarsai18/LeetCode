import math
class Solution:        
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        elif n == 3:
            return 1
        elif n == 4 or n == 5:
            return 2
        elif n == 6:
            return 3

        is_Prime = [True]*n
        is_Prime[0] = False
        is_Prime[1] = False
        
        i = 2
        while i*i < n:
            if is_Prime[i]:
                j = i*i
                while j < n:
                    is_Prime[j] = False
                    j += i
            i += 1
    
        count = 0
        for i in range(len(is_Prime)):
            if is_Prime[i]:
                count += 1
        return count
