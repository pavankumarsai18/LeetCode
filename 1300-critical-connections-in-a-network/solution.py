class Solution(object):
    rank = {}
    graph = defaultdict(list)
    conn_dict = {}
    
    def formGraph(self, n, connections):
        self.rank = {i:None for i in range(n)}
        self.graph = defaultdict(list)
        self.conn_dict = {}
        
        for edge in connections:
            u,v = edge[0],edge[1]
            self.graph[u].append(v)
            self.graph[v].append(u)
            
            self.conn_dict[(min(u,v), max(u,v))] = 1
    
    def dfs(self, node, discovery_rank):
        if self.rank[node]:
            return self.rank[node]
        
        self.rank[node] = discovery_rank
        min_rank = discovery_rank+1
        for neighbor in self.graph[node]:
            if self.rank[neighbor] and self.rank[neighbor] == discovery_rank - 1:
                continue
            recursive_rank = self.dfs(neighbor, discovery_rank + 1)
            if recursive_rank <= discovery_rank:
                del self.conn_dict[(min(node, neighbor), max(node, neighbor))]
            
            min_rank = min(min_rank, recursive_rank)
        return min_rank
    
    def criticalConnections(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
        self.formGraph(n, connections)
        self.dfs(0,0)
        
        result = list(self.conn_dict)
        return result
    
