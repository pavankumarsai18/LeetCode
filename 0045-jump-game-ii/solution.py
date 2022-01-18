class Solution(object):
    def BFS(self, numNodes, edges, s):

        # print(edges)
        visited = [False for _ in range(numNodes)]
        parent  = [-1 for _ in range(numNodes)]
        
        queue = deque()
        
        queue.append(s)
        visited[s] = True
        
        while len(queue) != 0:
            node = queue.popleft()
            # print("node ", node)
            for n in edges[node]:
                if n < numNodes and visited[n] == False:
                
                    parent[n] = node
                    queue.append(n)
                    visited[n] = True
            # print("queue ", queue)
        
        curNode = len(edges.keys()) - 1
        minJumps = 0
        
        # print("parent ", parent)
        
        while curNode != -1:
            # print("curNode ", curNode)
            curNode = parent[curNode]
            if curNode == -1:
                return minJumps
            else:
                minJumps += 1
                
        return minJumps
                    
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if len(nums) == 0:
            return 0
        
        if len(nums) == 1:
            return 0
        
        # DFS 
        # create a graph given the list and then do a DFS from the last node
        
        # Vertices [0, 1, 2... n - 1]
        
        # Edges
        edges = dict()
        for i in range(len(nums)):
            edges[i] = []
            if nums[i] != 0:
                for j in range(1, nums[i]+1):
                    if i+j < len(nums):
                        edges[i].append(i+j)
                    else:
                        break

        
        return self.BFS(len(nums), edges, 0)
        
            
        
