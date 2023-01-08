# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self._stack_ = [[nestedList, 0]]

    def make_top_stack_int(self):
        while self._stack_:
            top_list, index = self._stack_[-1]
            
            if len(top_list) == index:
                self._stack_.pop()
                continue
            
            if top_list[index].isInteger():
                break
            
            self._stack_[-1][1] += 1
            self._stack_.append([top_list[index].getList(), 0])

    def next(self) -> int:
        self.make_top_stack_int()
        cur_list, cur_index = self._stack_[-1]

        self._stack_[-1][1] += 1
        return cur_list[cur_index].getInteger()
        
    def hasNext(self) -> bool:
        self.make_top_stack_int()
        return len(self._stack_) > 0
         

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
