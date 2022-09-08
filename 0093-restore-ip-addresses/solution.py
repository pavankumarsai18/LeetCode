class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def isValidNumber(s: str) -> bool:
            if len(s) == 0 or len(s) > 3:
                return False

            return (s[0] == '0' and len(s) == 1) or (s[0] != '0' and 0 < int(s) <= 255)

        def findAllPossibleIP(s: str, dotsUsed: int) -> List[str]:
            if dotsUsed >= 4:
                return []
            elif dotsUsed == 3:
                if isValidNumber(s):
                    return [s]
                else:
                    return []

            ans = []
            dotsUsed += 1

            for length in range(1, 4):
                if isValidNumber(s[:length]):
                    curAns = s[:length] + '.'
                    for pos in findAllPossibleIP(s[length:], dotsUsed):
                        ans.append(curAns + pos)

            return ans
        
        return findAllPossibleIP(s, 0)
