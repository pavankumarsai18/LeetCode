class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        lo = 0
        hi = len(letters)-1
        
        ch_val = ord(target)
        
        while lo < hi:
            mid = lo + (hi - lo)//2
            
            diff = ord(letters[mid]) - ch_val
            if diff == 0:
                lo = mid + 1
            elif diff < 0:
                lo = mid + 1
            else:
                hi = mid
        if hi == len(letters) -1 and ord(target) >= ord(letters[hi]):
            return letters[0]
        return letters[lo]
