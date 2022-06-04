class UnionFind(object):
    def __init__(self):
        self.size    = 0
        self.groups  = 0
        self.parent  = []
        self.rank    = []
        
        self.itemIndex = dict()


    def add(self, item:tuple[int, int])->None:
        if item in self.itemIndex:
            return
        
        index = self.size
        self.itemIndex[item] = index
        self.parent.append(index)
        self.rank.append(0)
        
        self.size += 1
        self.groups += 1
        return
    
    def findItem(self, item:tuple[int, int])->int:
        if item in self.itemIndex:
            return self.find(self.itemIndex[item])
        return -1
    
    def find(self, index:int)->int:
        if self.parent[index] != index:
            self.parent[index] = self.find(self.parent[index])
        return self.parent[index]
    
    def unionItem(self, item1:tuple[int, int], item2:tuple[int, int])->None:
        self.union(self.itemIndex[item1], self.itemIndex[item2])
        return
    
    def union(self, index1:int, index2:int)->None:
        group1, group2 = self.find(index1), self.find(index2)
        if group1 != group2:
            if self.rank[group1] < self.rank[group2]:
                group1, group2 = group2, group1

            self.groups -= 1
            self.parent[group2] = group1
            self.rank[group1] += 1
        return
    
    def get_num_groups(self)->int:
        return self.groups
    
class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        
        
        def isValid(pos:tuple[int, int])->bool:
            r, c = pos
            return (0 <= r < m) and (0 <= c < n)
        
        islands = UnionFind()
                
        steps   = [(-1,0),(1,0),(0,1),(0,-1)] 
        
        result  = []
        
        for position in positions:
            pos = tuple(position)
            
            islands.add(pos)
            r, c = pos
            for step in steps:
                dr, dc = step
                adj = (r+dr, c+dc)
                if isValid(adj) and (islands.findItem(adj) != -1):
                    islands.unionItem(pos, adj)
            
            result.append(islands.get_num_groups())
        
        return result
                    
                
            
            
        
