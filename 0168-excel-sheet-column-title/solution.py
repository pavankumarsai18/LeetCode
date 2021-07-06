class Solution(object):
    def convertToTitle(self, columnNumber):
        """
        :type columnNumber: int
        :rtype: str
        """
        columnName = ""
        while columnNumber != 0:
            char = columnNumber%26
            if char == 0:
                char = 26
            columnNumber -= char
            columnNumber /= 26
            columnName = chr(char + 64) + columnName
            
        return columnName
        
