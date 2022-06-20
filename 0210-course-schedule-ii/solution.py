class Solution:
    def __init__(self):
        self.adjList  = None
        self.dfsVisited = []
        self.visited  = []
        
    def visit(self, node):
        self.visited[node] = True
        self.dfsVisited[node] = True
        
        for neighbor in self.adjList[node]:
            if self.dfsVisited[neighbor] or (not self.visited[neighbor] and self.visit(neighbor)):
                return True

        self.dfsVisited[node] = False
        self.courseOrder.append(node)
        return False
    
    def cycleInGraph(self):
        n = len(self.adjList)
        for node in range(n):
            if not self.visited[node] and self.visit(node):
                return True
        return False
    
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        # check for cycle in graph if exists return []
        # else do topsort
        
        self.adjList = [[] for _ in range(numCourses)]
        self.visited = [False]*numCourses
        self.dfsVisited = [False]*numCourses
        self.courseOrder = []
        
        for edge in prerequisites:
            self.adjList[edge[1]].append(edge[0])
        
        if self.cycleInGraph():
            return []

        return self.courseOrder[::-1]
