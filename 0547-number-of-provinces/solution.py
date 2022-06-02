class UnionFind(object):
    def __init__(self, n):
        self.n = n
        self.parent = [_ for _ in range(n)]
        self.rank    = [0 for _ in range(n)]
    
    def find(self, item):
        cur = item
        while self.parent[cur] != cur:
            cur = self.parent[cur]
        
        cur, group = item, cur
        while cur != group:
            cur, self.parent[cur] = self.parent[cur], group
        
        return group
    
    def union(self, item1, item2):
        group1, group2 = self.find(item1), self.find(item2)
        
        if group1 != group2:
            if self.rank[group1] < self.rank[group2]:
                group1, group2 = group2, group1
            
            self.rank[group1] += 1
            self.parent[group2] = group1
        
        return
    def numGroups(self):
        groups = set()
        for item in range(self.n):
            groups.add(self.find(item))
        return len(groups)

class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        n = len(isConnected)
        provinces = UnionFind(n)
        
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    provinces.union(i, j)
                    
        return provinces.numGroups()
        
