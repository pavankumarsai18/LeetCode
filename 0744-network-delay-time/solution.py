class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        
        # set source node as k
        # perform dijkstra on graph
        # get the maxTime if it inf retrun -1 else return maxTime
        
        adjList = [[] for _ in range(n+1)]
        
        for edge in times:
            u,v,weight = edge
            adjList[u].append((v,weight))
                
        def dijkstra(startVertex):
            dist = [float('inf') for _ in range(n+1)]
            dist[startVertex] = 0

            S = set()
    
            Q = [(0, k)]
            
            while Q:
                d, u = heapq.heappop(Q)
                if u in S or d > dist[u]:
                    continue
            
                S.add(u)
                for edge in adjList[u]:
                    v, dist_u_v = edge
                    if dist[v] > dist[u] + dist_u_v:
                        dist[v] = dist[u] + dist_u_v
                        heapq.heappush(Q, (dist[v], v))
                        
            return dist
        
        distances = dijkstra(k)
        result = float('-inf')
        
        for i in range(1, n+1):
            if distances[i] == float('inf'):
                return -1
            result = max(result, distances[i])
            
        return result
