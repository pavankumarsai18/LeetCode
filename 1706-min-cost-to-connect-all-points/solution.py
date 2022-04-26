class UnionFind(object):
    def __init__(self, n):
        self.group = [i for i in range(n)]
        self.rank = [0]*n
        
    def find(self, node):
        if self.group[node] != node:
            self.group[node] = self.find(self.group[node])
        return self.group[node]
    
    def inSameSet(self, a, b):
        groupA = self.find(a)
        groupB = self.find(b)
        if groupA == groupB:
            return True
        return False
    
    def join(self, a, b):
        groupA = self.find(a)
        groupB = self.find(b)
        
        if self.inSameSet(a, b):
            return False
        if self.rank[groupA] > self.rank[groupB]:
            self.group[groupB] = self.group[groupA]
        elif self.rank[groupA] < self.rank[groupB]:
            self.group[groupA] = self.group[groupB]
        else:
            self.group[groupA] = self.group[groupB]
            self.rank[groupB] += 1
        
        return True
        
    

class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        edges = list()
        
        for i in xrange(len(points)):
            for j in xrange(i+1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                manhattanDist = abs(x1 - x2) + abs(y1 - y2)
                edges.append((i, j, manhattanDist))

        
        edges.sort(key = lambda x: x[2])
        
        totalCost = 0
        
        pointSet = UnionFind(len(points))
        
        for edge in edges:
            start, end, dist = edge
            
            if pointSet.inSameSet(start, end):
                continue
            else:
                totalCost += dist
                pointSet.join(start, end)
        return totalCost
        
        
