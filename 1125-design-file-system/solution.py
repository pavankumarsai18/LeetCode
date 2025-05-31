class FileSystem:

    def __init__(self):
        self.paths = dict()

    def createPath(self, path: str, value: int) -> bool:
        dirs = path.split("/")
        parent_path = "/".join(dirs[:-1])
        if path not in self.paths and (len(dirs) == 2 or parent_path in self.paths):
            self.paths[path] = value
            return True
        return False
        

    def get(self, path: str) -> int:
        if path in self.paths:
            return self.paths[path]
        return -1
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
