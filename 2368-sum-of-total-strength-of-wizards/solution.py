class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        mod = 10**9 + 7
        n   = len(strength)
        prefixSum = [0]*(n+1)
        prePrefixSum = [0]*(n+2)
        
        for i, s in enumerate(strength):
            prefixSum[i+1] = (prefixSum[i] + s)%mod
        
        for i, sum_ in enumerate(prefixSum):
            prePrefixSum[i+1] = (prePrefixSum[i] + sum_)%mod
        
        
        left, right = [0]*n, [n]*n
        stack       = []
        
        for i, s in enumerate(strength):
            while stack and strength[stack[-1]] >= s:
                stack.pop()
            
            left[i] = -1 if not stack else stack[-1]
            stack.append(i)
            
        stack = []
        for i in range(n-1,-1,-1):
            while stack and strength[stack[-1]] > strength[i]:
                stack.pop()
            right[i] = n if not stack else stack[-1]
            stack.append(i)
        
        ans = 0
        for i, s in enumerate(strength):
            rightSum = ((prePrefixSum[right[i] + 1] - prePrefixSum[i + 1])*(i - left[i])%mod)
            
            leftSum = (prePrefixSum[i + 1] - prePrefixSum[left[i] + 1])*(right[i] - i)%mod
            
            ans += ((rightSum - leftSum)*s)%mod
            ans %= mod
        return ans
        
        
        
