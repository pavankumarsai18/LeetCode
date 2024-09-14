class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return True
        bed = [0] + flowerbed + [0]
        numPlanted = 0
        for i in range(1, len(flowerbed) + 1):
            if bed[i - 1] == bed[i] == bed[i+1] == 0:
                numPlanted += 1
                bed[i] = 1
            
            if numPlanted == n:
                return True

        return False

        
