class Solution(object):
    def multiply(self, mat1, mat2):
        indicies1 = dict()
        indicies2 = dict()
        
        for i in xrange(len(mat1)):
            row = mat1[i][:]
            R = []
            for j in xrange(len(row)):
                if row[j] != 0:
                    R.append(j)
            if len(R):
                indicies1[i] = R
        for j in xrange(len(mat2[0])):
            C = []
            for i in xrange(len(mat2)):
                if mat2[i][j] != 0:
                    C.append(i)
            if len(C):
                indicies2[j] = C

        result = [[0 for _ in xrange(len(mat2[0]))] for __ in xrange(len(mat1))]
        
        for i in indicies1:
            row = set(indicies1[i])
            for j in indicies2:
                col = set(indicies2[j])
                commonIndicies = row.intersection(col)
                if len(commonIndicies):
                    item = 0
                    for index in commonIndicies:
                        item += mat1[i][index]*mat2[index][j]
                    result[i][j] = item

        return result
