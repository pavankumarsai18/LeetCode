class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s

        zigZag = ["" for __ in xrange(numRows)]
        index = 0
        col = 0
        while col < len(s):
            while index <= numRows - 1 and col < len(s):
                zigZag[index] += s[col]
                index += 1
                col += 1
            index = numRows - 2
            while index >= 0 and col < len(s):
                zigZag[index] += s[col]
                col += 1
                index -= 1
            index = 1
                
        result = ""
        for row in zigZag:
            result += row
    
        return result
            
                
