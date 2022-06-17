class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = {}
        WORD_END = "$"
        for word in words:
            node = trie
            for ch in word:
                node = node.setdefault(ch, {})
            node[WORD_END] = word
        
        rows,cols = len(board), len(board[0])
        
        ans = set()
        def match(r, c, parent):
            ch = board[r][c]
            node = parent[ch]
            
            word_match = node.pop(WORD_END, False)
            
            if word_match:
                ans.add(word_match)
            
            board[r][c] = ""
            for (dr, dc) in [(-1,0),(1,0),(0,1),(0,-1)]:
                if (r+dr) >= rows or (r+dr) < 0 or (c+dc) >= cols or (c+dc) < 0:
                    continue
                
                if board[r+dr][c+dc] in node:
                    match(r+dr, c+dc, node)
            board[r][c] = ch
            
            if not node:
                parent.pop(ch)
            return
                
        
        for r in range(rows):
            for c in range(cols):
                if board[r][c] in trie:
                    match(r,c,trie)
        return list(ans)
        
        
