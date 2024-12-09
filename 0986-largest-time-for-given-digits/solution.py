class Solution(object):
    def all_permutations(self, arr):
        if len(arr) == 1:
            return [arr]
        elif len(arr) == 2:
            return [arr, arr[::-1]]
        
        seen = set()
        ans = []
        for i in range(len(arr)):
            removed_arr = arr[:i] + arr[i+1:]
            for permutation in self.all_permutations(removed_arr):
                for j in range(len(permutation)):
                    item = permutation[:j] + [arr[i]] + permutation[j:]
                    hash_item = ",".join(item)
                    if hash_item in seen:
                        continue
                    ans.append(item)
                    seen.add(hash_item)
        return ans
                
                

    def is_valid_time(self, time):
        if ":" not in time:
            return False
        
        h, m = time.split(":")    
        return 0 <= int(h) <= 23 and 0 <= int(m) < 59
    
    def max_time(self, time1, time2):
        time1_valid = self.is_valid_time(time1)
        time2_valid = self.is_valid_time(time2)
        if not time1_valid and time2_valid:
            return time2
        elif not time2_valid and time1_valid:
            return time1
        elif not time1_valid and not time2_valid:
            return ""
    
        h1, m1 = time1.split(":")
        h2, m2 = time2.split(":")
        
        if h1 > h2:
            return time1
        elif h2 > h1:
            return time2
        elif m1 > m2:
            return time1
        return time2
        
    def largestTimeFromDigits(self, arr):
        """
        :type arr: List[int]
        :rtype: str
        """
        
        permutations = self.all_permutations([str(item) for item in arr])
        # print(permutations)
        cur_max = ""
        for permutation in permutations:
            time = "".join(permutation[:2]) + ":" + "".join(permutation[2:])
            cur_max = self.max_time(cur_max, time)
        
        return cur_max
        
        
        
            
