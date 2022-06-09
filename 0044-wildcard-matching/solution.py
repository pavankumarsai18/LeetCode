class Solution(object):
    
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """       
        n, m = len(s), len(p)
        
        new_p = []
        index = 0
        isFirst = True
        while index < m:
            if p[index] != '*':
                new_p.append(p[index])
                index += 1
            while index < m and p[index] == '*':
                if isFirst:
                    new_p.append("*")
                    isFirst = False
                index += 1
            isFirst = True
            
        p = "".join(new_p)
        m = len(p)

        # dp[i][j] checks if the substring s[0:i] matches the re p[0:j]
        dp = [False]*(m+1)
        if m and p[0] == '*':
            dp[1] = True
        dp[0] = True

        for i in xrange(1, n+1):
            new_dp = [False]*(m+1)
            for j in xrange(1, m+1):
                if p[j-1] == '?' or s[i-1] == p[j-1]:
                    new_dp[j] = dp[j-1]
                elif p[j-1] == '*':
                    new_dp[j] = new_dp[j-1] or dp[j]
            dp = new_dp

        return dp[m]
        
