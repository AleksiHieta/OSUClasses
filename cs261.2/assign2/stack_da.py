# Course: CS261 - Data Structures
# Student Name: Aleksi Hieta
# Assignment: 2
# Description:
# Last revised:

from dynamic_array import *


class StackException(Exception):
    """
    Custom exception to be used by Stack class
    DO NOT CHANGE THIS METHOD IN ANY WAY
    """
    pass


class Stack:
    def __init__(self):
        """
        Init new stack based on Dynamic Array
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        self.da = DynamicArray()

    def __str__(self) -> str:
        """
        Return content of stack in human-readable form
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        out = "STACK: " + str(self.da.length()) + " elements. ["
        out += ', '.join([str(self.da.get_at_index(_))
                          for _ in range(self.da.length())])
        return out + ']'

    def is_empty(self) -> bool:
        """
        Return True is the stack is empty, False otherwise
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.da.is_empty()

    def size(self) -> int:
        """
        Return number of elements currently in the stack
        DO NOT CHANGE THIS METHOD IN ANY WAY
        """
        return self.da.length()

    def push(self, value: object) -> None:
        self.da.append(value)
        # print(self.da.size)
        pass

    def pop(self) -> object:
        if(self.da.size == 0):
            raise StackException
        data = self.da.data[self.da.size-1]
        self.da.remove_at_index(self.da.size-1)

        return data

    def top(self) -> object:
        if (self.da.size == 0):
            raise StackException
        return self.da.data[self.da.size-1]


# BASIC TESTING
if __name__ == "__main__":

    print("\n# push example 1")
    s = Stack()
    print(s)
    for value in [1, 2, 3, 4, 5]:
        s.push(value)
    print(s)

    print("\n pop example 0")
    print(s)
    s.pop()
    print(s)
    s.pop()
    print(s)
    s.pop()
    print(s)
    

    print("\n# pop example 1")
    s = Stack()
    try:
        print(s.pop())
    except Exception as e:
        print("Exception:", type(e))

    for value in [1, 2, 3, 4, 5]:
        s.push(value)

    for i in range(6):
        try:
            print(s.pop())
        except Exception as e:
            print("Exception:", type(e))

    print("\n# top example 1")
    s = Stack()
    try:
        s.top()
    except Exception as e:
        print("No elements in stack", type(e))
    s.push(10)
    s.push(20)
    print(s)
    print(s.top())
    print(s.top())
    print(s)

    """
    m = Stack()
    m.push('x')
    m.push('y')
    m.push('z')
    print(m)
    while not m.is_empty():
        m.pop()
        m.pop()
        print(m)
    print(m)
    """

    values = Stack()
    for i in range(16):
        print(values)
        print(i)
        print(values.da.capacity)
        if i % 2 == 0:
            print("mod2")
            values.push(i)
            print(values)
        elif i % 3 == 0:
            print("removing")
            values.pop()
            print(values)


