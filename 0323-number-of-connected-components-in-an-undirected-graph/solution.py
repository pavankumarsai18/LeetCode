class UnionFind(object):
    def __init__(self, n):
        self.parent = [_ for _ in range(n)]
        self.rank   = [0 for _ in range(n)]
        self.n      = n
        
    def find(self, item):  
        cur = item
        while self.parent[cur] != cur:
            cur = self.parent[cur]
        
        group, cur = cur, item
        while self.parent[cur] != group:
            cur = self.parent[cur]
            self.parent[cur] = group
        
        return group
    
    def union(self, item1, item2):
        group1, group2 = self.find(item1), self.find(item2)
        
        if group1 != group2:
            
            if self.rank[group1] < self.rank[group2]:
                group1, group2 = group2, group1
            
            self.parent[group2] = group1
            self.rank[group1] += 1
        return
    
    def numConnectedComponents(self):
        components = set()
        
        for item in range(self.n):
            components.add(self.find(item))
            
        return len(components)

class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        connected_components = UnionFind(n)
        for edge in edges:
            connected_components.union(edge[0], edge[1])
            
        return connected_components.numConnectedComponents()
