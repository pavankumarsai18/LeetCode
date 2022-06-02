
class Solution(object):
    class UnionFind(object):
        def __init__(self, n):
            self.n      = n
            self.rank   = [0 for _ in range(n)]
            self.parent = [_ for _ in range(n)]

        def find(self, item):
            if self.parent[item] != item:
                self.parent[item] = self.find(self.parent[item])

            return self.parent[item]

        def union(self, item1, item2):
            group1, group2 = self.find(item1), self.find(item2)

            if group1 != group2:
                if self.rank[group1] < self.rank[group2]:
                    group1, group2 = group2, group1

                self.parent[group2]  = group1
                self.rank[group1]   += 1
            return


        def inSameGroup(self):
            group = self.find(0)
            for item in range(1, self.n):
                if self.find(item) != group:
                    return False
            return True
        
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        
        # check for no cycle and all in same component
        if len(edges) != n-1:
            return False
        
        connected_component = self.UnionFind(n)
        
        for edge in edges:
            connected_component.union(edge[0], edge[1])
            
        return connected_component.inSameGroup()
