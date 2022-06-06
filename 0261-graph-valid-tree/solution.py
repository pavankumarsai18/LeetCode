

class UnionFind(object):
    def __init__(self, n):
        self.n = n
        self.parent  = [i for i in range(self.n)]
        self.rank    = [0 for _ in range(self.n)]
        self.num_groups = n
    def find(self, item):
        if self.parent[item] != item:
            self.parent[item] = self.find(self.parent[item])
        return self.parent[item]
    
    def union(self, item1, item2):
        group1, group2 = self.find(item1), self.find(item2)

        if group1 != group2:
            self.num_groups -= 1
            if self.rank[group2] > self.rank[group1]:
                group2, group1 = group1, group2
            self.parent[group2] = group1
            self.rank[group1] += 1
        return
    
    def get_num_groups(self):
        return self.num_groups

class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """

        if len(edges) != n-1:
            return False
        
        connected_components = UnionFind(n)

        for edge in edges:
            connected_components.union(edge[0], edge[1])
            
        return connected_components.get_num_groups() == 1

