# Course: CS261 - Data Structures
# Assignment: 5
# Student:
# Description:


# Import pre-written DynamicArray and LinkedList classes
from a5_include import *


class MinHeapException(Exception):
    """
    Custom exception to be used by MinHeap class
    DO NOT CHANGE THIS CLASS IN ANY WAY
    """
    pass


class MinHeap:
    def __init__(self, start_heap=None):
        """
        Initializes a new MinHeap
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.heap = DynamicArray()

        # populate MH with initial values (if provided)
        # before using this feature, implement add() method
        if start_heap:
            for node in start_heap:
                self.add(node)

    def __str__(self) -> str:
        """
        Return MH content in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return 'HEAP ' + str(self.heap)

    def is_empty(self) -> bool:
        """
        Return True if no elements in the heap, False otherwise
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.heap.length() == 0

    def add(self, node: object) -> None:
        print(self)
        if self.is_empty():
            self.heap.append(node)
        else:
            self.heap.append(node)        
            curr_idx = self.heap.length()-1
            
            while self.heap.get_at_index(0) != node:
                parent_idx = int((curr_idx-1)/2)
                #print(parent_idx)
                #print(curr_idx)
                if (self.heap.get_at_index(parent_idx) > node):
                    self.heap.swap(parent_idx, curr_idx)
                    curr_idx = parent_idx
                else:
                    return None
            pass
        pass

    def get_min(self) -> object:
        if self.heap[0] == None:
            raise MinHeapException
        return self.heap[0]

    def remove_min(self) -> object:
        if self.is_empty():
            raise MinHeapException
        min_thang = self.heap[0]

        self.heap.swap(0, self.heap.length()-1)
        self.heap.pop()


        max_idx = self.heap.length()-1
        curr_idx = 0
        while (self.heap.length() != 0):
            child1 = curr_idx * 2 + 1
            child2 = curr_idx * 2 + 2
            #print(self)
            #print("Curr: ", curr_idx)
            #print("Child 1: ", child1)
            #print("Child 2: ", child2)
            if ((child1 > max_idx) & (child2 > max_idx)):
                return min_thang
            elif child1 > max_idx:
                if self.heap[child2] < self.heap[curr_idx]:
                    self.heap.swap(child2, curr_idx)
                #print("Swapped: ", self.heap[child2], self.heap[curr_idx])
                curr_idx = child2
            elif child2 > max_idx:
                if self.heap[child1] < self.heap[curr_idx]:
                    self.heap.swap(child1, curr_idx)
                #print("Swapped: ", self.heap[child1], self.heap[curr_idx])
                curr_idx = child1
            else:
                #print("both children")
                if self.heap[child1] < self.heap[child2]:
                    if self.heap[child1] < self.heap[curr_idx]:
                        self.heap.swap(child1, curr_idx)
                    #print("Swapped: ", self.heap[child1], self.heap[curr_idx])
                    curr_idx = child1    
                #elif self.heap[child2] < self.heap[child1]:
                else:
                    if self.heap[child2] < self.heap[curr_idx]:
                        self.heap.swap(child2, curr_idx)
                    #print("Swapped: ", self.heap[child2], self.heap[curr_idx])
                    curr_idx = child2    

        return min_thang

    def build_heap(self, da: DynamicArray) -> None:
        sub = MinHeap()

        for i in range(da.length()):
            sub.add(da[i])

        for i in range(da.length()):
            da[i] = sub.heap[i]

        for i in range(da.length()):
            sub.heap[i] = None

        pass


# BASIC TESTING
if __name__ == '__main__':

    print("\nPDF - add example 1")
    print("-------------------")
    h = MinHeap()
    print(h, h.is_empty())
    for value in range(300, 200, -15):
        h.add(value)
        print(h)

    print("\nPDF - add example 2")
    print("-------------------")
    h = MinHeap(['fish', 'bird'])
    print(h)
    for value in ['monkey', 'zebra', 'elephant', 'horse', 'bear']:
        h.add(value)
        print(h)


    print("\nPDF - get_min example 1")
    print("-----------------------")
    h = MinHeap(['fish', 'bird'])
    print(h)
    print(h.get_min(), h.get_min())


    print("\nPDF - remove_min example 1")
    print("--------------------------")
    h = MinHeap([1, 10, 2, 9, 3, 8, 4, 7, 5, 6])
    while not h.is_empty():
        print(h, end=' ')
        print(h.remove_min())


    print("\nPDF - build_heap example 1")
    print("--------------------------")
    da = DynamicArray([100, 20, 6, 200, 90, 150, 300])
    h = MinHeap(['zebra', 'apple'])
    print(h)
    h.build_heap(da)
    print(h)
    da.set_at_index(0, 500)
    print(da)
    print(h)

    minimum = MinHeap([8, 22, 30, 14, 2, 6, 1])

    print(50 % 6)
    print(39 % 6)
    print(2 % 6)
    print(901 % 6)
    print(31 % 6)


