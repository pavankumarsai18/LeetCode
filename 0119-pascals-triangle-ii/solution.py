class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]
        else:
            prev_result = self.getRow(rowIndex - 1)
            result = [1]
            for i in range(len(prev_result)-1):
                result.append(prev_result[i] + prev_result[i+1])
            result.append(1)
            return result
