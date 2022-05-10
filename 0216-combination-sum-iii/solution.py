class Solution(object):
    
    
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def allCombs(k, n, memo):
            if (k, n) in memo:
                return memo[(k,n)]

            if n <= 0 or k <= 0:
                memo[(k,n)] = set(tuple())
                return set(tuple())

            elif 1 <= n <= 9 and k == 1:
                result = {(n,)}
                memo[(k,n)] = result
                return result

            result = set(tuple())

            for i in range(1, 10):
                temp = allCombs(k-1, n-i, memo)
                for item in temp:
                    if i in list(item) or len(item) != k-1:
                        continue
                    else:                    
                        newItem = copy.deepcopy(list(item))
                        newItem.append(i)
                        newItem.sort()
                        result.add(tuple(newItem))

            memo[(k,n)] = result
            return result
        
        memo = dict()
        allCombs = allCombs(k, n, memo)
        result = set()
        for comb in allCombs:
            if len(comb) == k:
                item = list(comb)
                result.add(tuple(item))
            
        return list(result)
