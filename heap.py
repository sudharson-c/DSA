class MinHeap:

    def __init__(self):
        self.array  = []
    
    def parent(self,i):
        return (i-1)//2
    
    def left_child(self,i):
        return (i*2)+1
    
    def right_child(self,i):
        return (i*2)+2
    
    def insert(self,num):
        self.array.append(num)
        self.heapify_up(len(self.array)-1)

    def heapify_up(self,i):
        while i > 0 and self.array[i] < self.array[self.parent(i)]:
            self.array[i], self.array[self.parent(i)] = self.array[self.parent(i)], self.array[i]
            i  = self.parent(i)

    def pop(self):
        if len(self.array) == 0:
            return "Heap Empty"
        if len(self.array) == 1:
            return self.array.pop() 
        
        root = self.array[0]
        self.array[0] = self.array.pop()
        self.heapify_down(0)

        return root
            
    def heapify_down(self,i):
        smallest = i    
        left = self.left_child(i)
        right = self.right_child(i)

        if left<self.size() and self.array[left] < self.array[smallest]:
            smallest = left
        if right<self.size() and self.array[right] < self.array[smallest]:
            smallest = right
        
        if smallest != i:
            self.array[i],self.array[smallest] = self.array[smallest],self.array[i]
            self.heapify_down(smallest)

    def peek(self):
        return self.array[0] if self.array else "Heap Empty"
    
    def size(self):
        return len(self.array)
    
    def print(self):
        print(self.array)

heap = MinHeap()
heap.print()
heap.insert(10)
heap.insert(20)
heap.print()
heap.insert(15)
heap.print()
print(heap.pop())
heap.print()
        