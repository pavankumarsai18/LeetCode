class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        if '.' in queryIP and ':' not in queryIP:
            nums = queryIP.split('.')
            if len(nums) != 4:
                return 'Neither'
            for num in nums:
                if not num:
                    return 'Neither'
                elif num.isnumeric() and 0 <= int(num) <= 255:
                    if len(num) > 1 and num[0] == '0':
                        return 'Neither'
                else:
                    return 'Neither'
            return 'IPv4'
        elif ':' in queryIP and '.' not in queryIP:
            hexChars = {'0', '1', '2', '3','4', '5', '6', '7', '8', '9','a', 'b', 'c', 'd', 'e', 'f'}
            nums = queryIP.split(':')
            if len(nums) != 8:
                return 'Neither'
            for num in nums:
                if 1 <= len(num) <= 4:
                    numChars = set(num.lower())
                    for ch in numChars:
                        if ch not in hexChars:
                            return 'Neither'
                else:
                    return 'Neither'

            return 'IPv6'
        
        return 'Neither'
                
