class Solution:
    def __play_optimally(self, piles, remaning, memo):
        key = ",".join(map(str, piles))
        if key in memo:
            return memo[key]
        
        if remaning == 0:
            return False

        for i in range(len(piles)):
            for num_removed in range(1, piles[i] + 1):
                piles[i] -= num_removed
                next_state = sorted(piles)
                if not self.__play_optimally(next_state, remaning - num_removed, memo):
                    memo[key] = True
                    return True
                piles[i] += num_removed
        memo[key] = False
        return False

    def nimGame(self, piles: List[int]) -> bool:
        total_piles = sum(piles)
        memo = {}
        return self.__play_optimally(piles, total_piles, memo)
