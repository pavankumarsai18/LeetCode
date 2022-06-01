class Solution:
    
    def twoSum(self, nums:List[int], target:int, num_count:dict[int,int]) -> List[List[int]]:   
        result = set()
        
        for num,count in num_count.items():
            if target - num in num_count:
                item = tuple(sorted([num, target-num]))

                if target-num == num and num_count[num] > 1:
                    result.add(item)
                elif target - num != num and num_count[num] > 0 and num_count[target-num] > 0:
                    result.add(item)
                    
    
        return [list(item) for item in result]
    
    def threeSum(self, nums:List[int], target:int, num_count:dict[int, int])->List[List[int]]:
        result = set()
        
        for num, count in num_count.items():
            num_count[num] -= 1
            
            for item in self.twoSum(nums, target-num, num_count):
                if num_count[num] >= 0:
                    item.append(num)
                    newItem = tuple(sorted(item))
                    result.add(newItem)
            
            num_count[num] += 1
        
        
        return [list(item) for item in result]

        
        
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        
        num_count = {}
        for num in nums:
            if num not in num_count:
                num_count[num] = 0
            num_count[num] += 1
        
        result = set()
        for num, count in num_count.items():
            num_count[num] -= 1
            
            for item in self.threeSum(nums, target-num, num_count):
                if num_count[num] >= 0:
                    item.append(num)
                    newItem = tuple(sorted(item))
                    result.add(newItem)
                
            num_count[num] += 1
            
        return [list(item) for item in result]
