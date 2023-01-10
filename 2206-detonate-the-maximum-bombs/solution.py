class Solution:
    def detonate(self,  index:int, bombs: List[List[int]], detonated: List[bool])->int:
        def inRange(bomb1: List[int], bomb2: List[int])->bool:
            x, y, r = bomb1
            X, Y, _ = bomb2

            return (x - X)**2 + (y - Y)**2 <= r**2

        detonated[index] = True

        for i, bomb in enumerate(bombs):
            if i != index and not detonated[i] and inRange(bombs[index], bomb):
                detonated[i] = True
                self.detonate(i, bombs, detonated)

        ans = sum(bool(x) for x in detonated)
        return ans


    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        ans = 0

        cache = [-1]*n

        for i, bomb in enumerate(bombs):
            if cache[i] == -1:
                detonated = [False]*n
                num_detonated = self.detonate(i, bombs, detonated)
                for j in range(len(detonated)):
                    if detonated[j]:
                        cache[j] = max(cache[j], num_detonated)

        return max(cache)
