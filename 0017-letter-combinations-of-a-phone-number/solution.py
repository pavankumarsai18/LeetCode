class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        n_l = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs","8":"tuv","9":"wxyz"}
        numbers = [2, 3, 4, 5, 6, 7, 8, 9]
        for number in numbers:
            if digits == str(number):
                p = n_l[digits]
                result = []
                for i in p:
                    result.append(i)
                return result
        else:
            r1 = self.letterCombinations(digits[:len(digits)//2])
            r2 = self.letterCombinations(digits[len(digits)//2:])
            result = []
            for i in range(len(r2)):
                for j in range(len(r1)):
                    result.append(r1[j] + r2[i])
            return result             
        
                
        
