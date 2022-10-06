class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        n  = len(regular)
        
        ans = [0]*(n+1)
        regularRoute = [0]*(n+1)
        expressRoute  = [0]*(n+1)
        
        expressRoute[0] = expressCost
        for stop in range(1, n+1):
            regularRoute[stop] = min(regularRoute[stop-1], expressRoute[stop-1]) + regular[stop-1]
            expressRoute[stop] = min(expressRoute[stop-1] , regularRoute[stop-1] + expressCost) + express[stop-1]
            

            ans[stop] = min(regularRoute[stop], expressRoute[stop])
            # print(f"express {expressRoute[stop]} regular {regularRoute[stop]} ans[stop] {ans[stop]}")
        
        return ans[1:]
