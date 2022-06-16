class UnionFind(object):
    def __init__(self, numRows, numCols):
        self.itemMap = defaultdict(int)
        self.items   = []
        self.size    = 0
        self.parent  = []
        self.rank    = []
        self.numGroups = 0
        self.numRows = numRows
        self.numCols = numCols
        
    def addItem(self, item):
        if item in self.itemMap:
            return
        
        self.itemMap[item] = self.size
        self.parent.append(self.size)
        self.rank.append(0)
        self.size += 1
        self.numGroups += 1
    
    def findItem(self, item):
        index = self.itemMap[item]
        return self.find(index)
    
    def find(self, index):
        cur = index
        while self.parent[cur] != cur:
            cur = self.parent[cur]
        return cur
    
    def union(self, item1, item2):
        if item1 not in self.itemMap:
            self.addItem(item1)
        if item2 not in self.itemMap:
            self.addItem(item2)
            
        group1, group2 = self.findItem(item1), self.findItem(item2)
        
        if group1 != group2:
            if self.rank[group1] < self.rank[group2]:
                group1, group2 = group2, group1
            
            self.parent[group2] = group1
            self.rank[group1] += 1
            self.numGroups -= 1
            
            
    def getGroups(self):
        groupMap = defaultdict(set)
        
        for item,index in self.itemMap.items():
            groupMap[self.find(index)].add(item)
        
        # print(f"groupMaps {groupMap}")
        delete = set()
        for groupId, items in groupMap.items():
            for i in range(self.numRows):
                if (i, 0) in items or (i, self.numCols-1) in items:
                    # print(f"groupId {groupId} needs to be deleted")
                    delete.add(groupId)
                    break
            if groupId not in delete:
                for j in range(self.numCols):
                    if (0, j) in items or (self.numRows-1, j) in items:
                        # print(f"groupId {groupId} needs to be deleted")
                        delete.add(groupId)
                        break
        
        for groupId in delete:
            del groupMap[groupId]
        # print(f"group after deletion {groupMap}")
        ans = set()
        for item in groupMap.values():
            ans = ans.union(item)
        # print(f"ans {ans}")

        return ans
        
    
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        steps = [(-1,0),(0,-1),(0,1),(1,0)]
        
        numRows = len(board)
        numCols = len(board[0])
        
        regions = UnionFind(numRows, numCols)
        target  = 'O'
        
        for i in range(numRows):
            for j in range(numCols):
                if board[i][j] == target:
                    # print(f"O at {i,j}")
                    regions.addItem((i,j))
                    for step in steps:
                        di, dj = step
                        if 0 <= (i+di) < numRows and 0 <= (j+dj) < numCols and board[i+di][j+dj] == target:
                            # print(f"Union {i,j} {i+di,j+dj}")
                            regions.union((i,j), (i+di, j+dj))
        
        for pos in regions.getGroups():
            r, c = pos
            board[r][c] = 'X'
            
                            
        return 
        
        
