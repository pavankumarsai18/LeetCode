class Solution:
    def removeDuplicates(self, S: str) -> str:
        result = ""
        for char in S:
            if len(result) == 0:
                result += char
            else:
                if result[len(result)-1] == char:
                    result = result[:-1]
                else:
                    result += char
     
        return result
    
