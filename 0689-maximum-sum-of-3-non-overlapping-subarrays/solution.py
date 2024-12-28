class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        prefix_sum = [0 for _ in range(len(nums) + 1)]
        for i in range(len(nums)):
            prefix_sum[i+1] = prefix_sum[i] + nums[i]
        
        memo = dict()
        num_subarrays = 3

        def get_sum_range(left, right):
            return prefix_sum[right + 1] - prefix_sum[left]
        def get_subarray_sum(start):
            return get_sum_range(start, start + k - 1)

        def max_subarray_sum(start_idx, count):
            if (start_idx, count) in memo:
                return memo[(start_idx, count)]
            
            if start_idx + k > len(nums) or count >= num_subarrays:
                return 0

            #case 1: include start_idx
            include = max_subarray_sum(start_idx+k, count+1) +\
                        get_subarray_sum(start_idx)

            # case 2: do not include
            do_not_include =  max_subarray_sum(start_idx+1, count)

            memo[(start_idx, count)] = max(include, do_not_include)
            return max(include, do_not_include)
        
        def find_path(start_idx, count, path):
            if start_idx + k > len(nums) or count >= num_subarrays:
                return 0
            #case 1: include start_idx
            include = max_subarray_sum(start_idx+k, count+1) +\
                        get_subarray_sum(start_idx)

            # case 2: do not include
            do_not_include =  max_subarray_sum(start_idx+1, count)
            if include >= do_not_include:
                path.append(start_idx)
                find_path(start_idx+k, count+1, path)
            else:
                find_path(start_idx+1, count, path)

        max_sum = max_subarray_sum(0,0)

        path = []
        find_path(0, 0, path)
        return path





