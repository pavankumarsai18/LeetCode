class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adjList = {ch: set() for word in words for ch in word}
        
        for i in range(len(words)-1):
            w1, w2 = words[i], words[i+1]
            minLength = min(len(w1), len(w2))
            
            if len(w1) > len(w2) and w1[:minLength] == w2[:minLength]:
                return ""
        
            for j in range(minLength):
                if w1[j] != w2[j]:
                    adjList[w1[j]].add(w2[j])
                    break
        
        visited    = defaultdict(bool)
        dfsVisited = defaultdict(bool)
        ans = []
        
        def dfs():
            for ch in adjList.keys():
                if ch not in visited and visit(ch):
                    return True
            return False
        
        def visit(ch):
            if ch in visited:
                return
            
            visited[ch] = True
            dfsVisited[ch] = True
            for neighbor in adjList[ch]:
                if dfsVisited[neighbor] or (neighbor not in visited and visit(neighbor)):
                    return True
    
            dfsVisited[ch] = False
            ans.append(ch)
        
        if dfs():
            return ""
        ans.reverse()
        return "".join(ans)
