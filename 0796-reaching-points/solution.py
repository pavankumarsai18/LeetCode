class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        
        # sx, sy -> tx, ty
        # sx, sy <- tx, ty
        
        while tx >= sx and ty >= sy :
             # print(f"{sx} {sy} {tx} {ty}")
            if sx == tx and sy == ty:
                return True
            
            if (tx > ty):
                if ty > sy:
                    tx %= ty
                else:
                    return (tx - sx)%sy == 0
            else:
                if tx > sx:
                    ty %= tx
                else:
                    return (ty - sy)%tx == 0
        
            
        return tx == sx and ty == sy
