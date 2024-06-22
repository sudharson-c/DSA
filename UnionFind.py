

class UnionFind:
    def __init__(self, n):
        self.id = [x for x in range(n)]

    def root(self,x):
        while x!=self.id[x]:
            x=self.id[x]
        return x
    def check(self,x,y):
        return self.root(x)==self.root(y)
    
    def union(self,x,y):
        rootOfX = self.root(x)
        rootOfY = self.root(y)
        self.id[rootOfX] = rootOfY

uf = UnionFind(10)
uf.union(1,2)
print(uf.id)
