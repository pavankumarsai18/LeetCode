class Solution(object):
    def findAllStrobogrammatic(self,n, memo):
        if n in memo:
            return memo[n]
        if n == 1:
            memo[n] = ["1", "0", "8"]
            return memo[n]
        elif n == 2:
            memo[n] = ["11", "88", "69", "96"]
            return memo[n]
        else:
            result = set()
            subResult = self.findStrobogrammatic(n - 1)
            for digit in ["1", "0", "8"]:
                for num in subResult:
                    i = len(num)//2
                    temp = num[:i] + digit + num[i:]
                    tempCopy = ""
                    for i in xrange(len(temp)-1,-1,-1):
                        if temp[i] == "6":
                            tempCopy += "9"
                        elif temp[i] == "9":
                            tempCopy += "6"
                        else:
                            tempCopy += temp[i]

                    if tempCopy == temp:
                        result.add(temp)
            if n%2 == 0:
                subResult = self.findStrobogrammatic(n - 2)
                for digits in ["11", "00", "88", "69", "96"]:
                    digit1 = digits[0]
                    digit2 = digits[1]
                    
                    for num in subResult:
                        i = len(num)//2
                        j = len(num)//2
                        while i >= 0 and j < len(num):
                            temp = num[:i] + digit1 + num[i:j] + digit2 + num[j:]
                            i -= 1
                            j += 1
                            tempCopy = ""
                            for i in xrange(len(temp)-1,-1,-1):
                                if temp[i] == "6":
                                    tempCopy += "9"
                                elif temp[i] == "9":
                                    tempCopy += "6"
                                else:
                                    tempCopy += temp[i]
                            
                            if tempCopy == temp:
                                result.add(temp)
            # print(result)
            memo[n] = list(result)
            return memo[n]
        
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        memo = dict()
        return self.findAllStrobogrammatic(n, memo)
