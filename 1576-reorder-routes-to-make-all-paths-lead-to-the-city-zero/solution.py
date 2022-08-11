class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        edges = defaultdict(list)

        for c in connections:
            edges[c[0]].append((0,c[1]))
            edges[c[1]].append((1,c[0]))
        
        backward, forward = 0, 1        
        ans = 0
        
        visited = set()

        queue = collections.deque()
        queue.append((0,0))

        while queue:
            direction, u = queue.popleft()

            if u in visited:
                break

            visited.add(u)

            for neigh in edges[u]:
                edgeDir, v = neigh 
                if v in visited:
                    continue
                if edgeDir == backward:
                    ans += 1

                queue.append((edgeDir, v))

        return ans
                    
                
            
        
        
        
        
