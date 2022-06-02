class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        def getAllSubSets(numCount, cache):
            if str(sorted(numCount.items())) in cache:
                return cache[str(sorted(numCount.items()))]
            
            result = set()
            
            for num, count in numCount.items():
                if count > 0:
                    numCount[num] -= 1
                    
                    withoutNum = getAllSubSets(numCount, cache)
    
                    for subset in withoutNum:
                        result.add(subset)
                        
                        newItem = list(subset)
                        newItem.append(num)
                        newItem.sort()
                        result.add(tuple(newItem))
                    
                    result.add(tuple([num]))
                    
                    numCount[num] += 1
            
            # print(result, numCount)
            cache[str(sorted(numCount.items()))] = result
            return result
                        
        numCount = dict()
        for num in nums:
            if num not in numCount:
                numCount[num] = 0
            numCount[num] += 1
        result = getAllSubSets(numCount, {})
        
        return  [[]] + [list(item) for item in result]
