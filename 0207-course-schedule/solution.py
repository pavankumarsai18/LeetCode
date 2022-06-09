class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        
        n = numCourses
        visited    = [False]*n
        dfsVisited = [False]*n
        
        
        def cycleExists():
            for node in range(n):
                if not visited[node] and dfs(node):
                        return True
            return False
        
        def dfs(node):
            visited[node] = True
            dfsVisited[node] = True
            
            for neighbor in adjList[node]:
                if not visited[neighbor] and dfs(neighbor):
                    return True
                elif dfsVisited[neighbor]:
                    return True

            dfsVisited[node] = False
            return False
                
                
        
        adjList = [[] for _ in range(n)]
        
        for edge in prerequisites:
            adjList[edge[0]].append(edge[1])

        return not cycleExists()
