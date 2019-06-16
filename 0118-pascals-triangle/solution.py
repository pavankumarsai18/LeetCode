class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]
        else:
            new = [1]
            result = self.generate(numRows-1)
            for i in range(len(result[-1])-1):
                new.append(result[-1][i] + result[-1][i+1])
            new.append(1)
            result.append(new)
            return result
